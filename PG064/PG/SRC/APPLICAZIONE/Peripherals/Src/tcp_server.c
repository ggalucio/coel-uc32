/*
 * tcp_server.c
 *
 *  Created on: 24 nov 2021
 *      Author: paoloc
 */

#include "../Inc/tcp_server.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "stdio.h"
#include "string.h"
#include "cmsis_os.h"

/* structure for maintaing connection infos to be passed as argument
   to LwIP callbacks*/
struct tcp_echoserver_struct
{
  u8_t state;             /* current connection state */
  u8_t retries;
  struct tcp_pcb *pcb;    /* pointer on the current tcp_pcb */
  struct pbuf *p;         /* pointer on the received/to be transmitted pbuf */
};

static struct tcp_pcb *tcp_echoserver_pcb;
struct tcp_echoserver_struct *ess;

/* ECHO protocol states */
enum tcp_echoserver_states
{
  ES_NONE = 0,
  ES_ACCEPTED,
  ES_RECEIVED,
  ES_CLOSING
};

static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static void tcp_echoserver_error(void *arg, err_t err);
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es);

BOOLEAN tcp_echoserver_send_data(BYTE* pData, WORD size){

	if(READ_MODBUSTCPIP_PERIPH_STATUS() == 0 || ethHandler.tes->p == NULL){
		return AT_FALSE;
	}

	memcpy((char *)modbusTcpIpTransceiver.TxBuffer, (char *)pData, sizeof(BYTE) * size);
	memcpy((char *)ethHandler.tes->p->payload, (char *)pData, sizeof(BYTE) * size);
	ethHandler.tes->p->tot_len 	= size;
	ethHandler.tes->p->len 		= size;

	tcp_sent(ethHandler.tes->pcb, tcp_echoserver_sent);

	tcp_echoserver_send(ethHandler.tes->pcb, ethHandler.tes);

	ethHandler.TxDataLen = size;
	modbusTCPIPComm.State = MB_TRANSMITTED;

	return AT_TRUE;
}

/**
  * @brief  Initializes the tcp echo server
  * @param  None
  * @retval None
  */
BOOLEAN InitModbusTcpIpServer(void)
{
  /* create new tcp pcb */
  tcp_echoserver_pcb = tcp_new();

  err_t err = ERR_ARG;

  BOOLEAN resOk = AT_FALSE;

  if (tcp_echoserver_pcb != NULL)
  {
    ip_addr_t ipaddr;

    IP_ADDR4(&ipaddr, 192, 168, 5, 9);
    //IP_ADDR4(&ipaddr,BOARD_IP1_ADDRESS, BOARD_IP2_ADDRESS, BOARD_IP3_ADDRESS, BOARD_IP4_ADDRESS);

    /* bind echo_pcb to port */
    //err = tcp_bind(tcp_echoserver_pcb, &ipaddr, BOARD_PORT_ADDRESS);
    err = tcp_bind(tcp_echoserver_pcb, &ipaddr, 502);

    resOk = err == ERR_OK;

    if (resOk)
    {
      /* start tcp listening for echo_pcb */
      tcp_echoserver_pcb = tcp_listen(tcp_echoserver_pcb);

      /* initialize LwIP tcp_accept callback function */
      tcp_accept(tcp_echoserver_pcb, tcp_echoserver_accept);

      tcp_echoserver_pcb->so_options |= SOF_KEEPALIVE;	// Enable keep alive
      tcp_echoserver_pcb->keep_intvl = 1000;
      modbusTCPIPComm.Send = tcp_echoserver_send_data;

    }
    else
    {
      /* deallocate the pcb */
    	DeInitModbusTcpIpServer();
    }
  }

  return resOk;
}

void tcp_echoserver_received(struct tcp_echoserver_struct *es){
 	BYTE len = es->p->tot_len;
  	//memset (modbusTcpIpTransceiver.RxBuffer, '\0', sizeof(char) * len);
  	memcpy(modbusTcpIpTransceiver.RxBuffer, (char *)es->p->payload, len);

  	ethHandler.tes = es;
  	modbusTCPIPComm.State = MB_RECEIVED;

	if(modbusTCPIPComm.ReceiveClbk){
		modbusTCPIPComm.ReceiveClbk(modbusTcpIpTransceiver.RxBuffer, len);
		ResetTcpIpModbusTimer();
	}
}

/**
  * @brief  This function is the implementation of tcp_accept LwIP callback
  * @param  arg: not used
  * @param  newpcb: pointer on tcp_pcb struct for the newly created tcp connection
  * @param  err: not used
  * @retval err_t: error status
  */
static err_t tcp_echoserver_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
  err_t ret_err;
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  /* set priority for the newly accepted tcp connection newpcb */
  tcp_setprio(newpcb, TCP_PRIO_MIN);

  /* allocate structure es to maintain tcp connection informations */
  es = (struct tcp_echoserver_struct *)mem_malloc(sizeof(struct tcp_echoserver_struct));

  if (es != NULL)
  {
    es->state = ES_ACCEPTED;
    es->pcb = newpcb;
    es->retries = 0;
    es->p = NULL;

    /* pass newly allocated es structure as argument to newpcb */
    tcp_arg(newpcb, es);

    /* initialize lwip tcp_recv callback function for newpcb  */
    tcp_recv(newpcb, tcp_echoserver_recv);

    /* initialize lwip tcp_err callback function for newpcb  */
    tcp_err(newpcb, tcp_echoserver_error);

    /* initialize lwip tcp_poll callback function for newpcb */
    //tcp_poll(newpcb, tcp_echoserver_poll, 0);

    SET_MODBUSTCPIP_PERIPH_STATUS();

    ess = es;

    ret_err = ERR_OK;
  }
  else
  {
    /*  close tcp connection */
    tcp_echoserver_connection_close(newpcb, es);
    /* return memory error */
    ret_err = ERR_MEM;
  }

  ethHandler.connAvailable =  ret_err == ERR_OK ? AT_TRUE : AT_FALSE;
  return ret_err;
}


/**
  * @brief  This function is the implementation for tcp_recv LwIP callback
  * @param  arg: pointer on a argument for the tcp_pcb connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  pbuf: pointer on the received pbuf
  * @param  err: error information regarding the reveived pbuf
  * @retval err_t: error code
  */
static err_t tcp_echoserver_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
	/*if(modbusTCPIPComm.State == MB_RECEIVED)
		return ERR_OK;*/

	ethHandler.tpcb = tpcb;
  struct tcp_echoserver_struct *es;
  err_t ret_err;

  LWIP_ASSERT("arg != NULL",arg != NULL);

  es = (struct tcp_echoserver_struct *)arg;

  /* if we receive an empty tcp frame from client => close connection */
  if (p == NULL)
  {

    /* remote host closed connection */
    es->state = ES_CLOSING;
    if(es->p == NULL)
    {
       /* we're done sending, close connection */
       tcp_echoserver_connection_close(es->pcb, es);
    }
    else
    {
      /* we're not done yet */
      /* acknowledge received packet */
      // tcp_sent(tpcb, tcp_echoserver_sent); // PC88

      /* send remaining data*/
      // tcp_echoserver_send(tpcb, es); // PC88
      tcp_echoserver_received(es);
    }
    ret_err = ERR_OK;
  }
  /* else : a non empty frame was received from client but for some reason err != ERR_OK */
  else if(err != ERR_OK)
  {
    /* free received pbuf*/
    if (p != NULL)
    {
      es->p = NULL;
      pbuf_free(p);
    }
    ret_err = err;
  }
  else if(es->state == ES_ACCEPTED)
  {
	  printf("Accepted\n");
    /* first data chunk in p->payload */
    es->state = ES_RECEIVED;

    /* store reference to incoming pbuf (chain) */
    es->p = p;

    tcp_echoserver_received(es);
    ret_err = ERR_OK;
  }
  else if (es->state == ES_RECEIVED)
  {
    /* more data received from client and previous data has been already sent*/
    if(es->p == NULL)
    {
      es->p = p;

      /* send back received data */
      // tcp_echoserver_send(tpcb, es);	//PC88
      tcp_echoserver_received(es);
    }
    else
    {
      pbuf_free(es->p);
      es->p = NULL;
      tcp_echoserver_connection_close(es->pcb, es);
	  ret_err = ERR_OK;
    }
    ret_err = ERR_OK;
  }
  else if(es->state == ES_CLOSING)
  {
    /* odd case, remote side closing twice, trash data */
      tcp_recved(tpcb, p->tot_len);
      es->p = NULL;
      pbuf_free(p);
	  ret_err = ERR_OK;
  }
  else
  {
    /* unkown es->state, trash data  */
    tcp_recved(tpcb, p->tot_len);
    es->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }

  return ret_err;
}

int countErr = 0;
/**
  * @brief  This function implements the tcp_err callback function (called
  *         when a fatal tcp_connection error occurs.
  * @param  arg: pointer on argument parameter
  * @param  err: not used
  * @retval None
  */
static void tcp_echoserver_error(void *arg, err_t err)
{
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(err);

  es = (struct tcp_echoserver_struct *)arg;

  if (es != NULL)
  {
	tcp_echoserver_connection_close(es->pcb, es);
  }

  countErr++;
  printf("Errors: %d\n", countErr);
}

/**
  * @brief  This function implements the tcp_sent LwIP callback (called when ACK
  *         is received from remote host for sent data)
  * @param  None
  * @retval None
  */
static err_t tcp_echoserver_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
  struct tcp_echoserver_struct *es;

  LWIP_UNUSED_ARG(len);

  es = (struct tcp_echoserver_struct *)arg;
  es->retries = 0;

  if(es->p != NULL)
  {
    /* still got pbufs to send */
      //tcp_sent(tpcb, tcp_echoserver_sent); //PC88
	  //tcp_echoserver_send(tpcb, es); //PC88
	  //tcp_echoserver_received(es);
  }
  else
  {
    /* if no more data to send and client closed connection*/
    if(es->state == ES_CLOSING)
      tcp_echoserver_connection_close(tpcb, es);
  }


	//if(ethHandler.TxDataLen == len)
		modbusTCPIPComm.State = MB_TRANSMITTED;

  return ERR_OK;
}

/**
  * @brief  This function is used to send data for tcp connection
  * @param  tpcb: pointer on the tcp_pcb connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
static void tcp_echoserver_send(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{
  struct pbuf *ptr;
  err_t wr_err = ERR_OK;
  err_t out_err = ERR_OK;

  while ((wr_err == ERR_OK) &&
         (es->p != NULL) &&
         (es->p->len <= tcp_sndbuf(tpcb)))
  {

    /* get pointer on pbuf from es structure */
    ptr = es->p;

    /* enqueue data for transmission */
    wr_err  = tcp_write(tpcb, ptr->payload, ptr->len, 1);
    out_err = tcp_output(tpcb);
    if (wr_err == ERR_OK && out_err == ERR_OK)
    {


      u16_t plen;
      u8_t freed;

      plen = ptr->len;

      /* continue with next pbuf in chain (if any) */
      es->p = ptr->next;

      if(es->p != NULL)
      {
        /* increment reference count for es->p */
        pbuf_ref(es->p);
      }

     /* chop first pbuf from chain */
      do
      {
        /* try hard to free pbuf */
        freed = pbuf_free(ptr);
      }
      while(freed == 0);
     /* we can read more data now */
     tcp_recved(tpcb, plen);
   }
  /* else if(wr_err == ERR_MEM)
   {
      // we are low on memory, try later / harder, defer to poll
     es->p = ptr;
   }*/
   else
   {
     /* other problem ?? */
	   es->p = ptr;
   }
  }
}

/**
  * @brief  This functions closes the tcp connection
  * @param  tcp_pcb: pointer on the tcp connection
  * @param  es: pointer on echo_state structure
  * @retval None
  */
static void tcp_echoserver_connection_close(struct tcp_pcb *tpcb, struct tcp_echoserver_struct *es)
{
  ethHandler.connAvailable = AT_FALSE;
  RESET_MODBUSTCPIP_PERIPH_STATUS();

  /* remove all callbacks */
  tcp_arg(tpcb, NULL);
  tcp_sent(tpcb, NULL);
  tcp_recv(tpcb, NULL);
  tcp_err(tpcb, NULL);
  tcp_poll(tpcb, NULL, 0);

  /* delete es structure */
  if (es != NULL)
  {
    mem_free(es);
  }

  tcp_abort(tpcb);

  /* close tcp connection */
  tcp_close(tpcb);

  memp_free(MEMP_TCP_PCB, tpcb);

  tpcb = NULL;

  modbusTCPIPComm.State = MB_READY;
}

void DeInitModbusTcpIpServer(){
	if(tcp_echoserver_pcb){
		tcp_echoserver_pcb->state = LISTEN;
		tcp_close(tcp_echoserver_pcb);
		memp_free(MEMP_TCP_PCB, tcp_echoserver_pcb );
		memset(tcp_echoserver_pcb, 0, sizeof(struct tcp_pcb));
		tcp_echoserver_pcb = NULL;
	}

	if(ess != NULL){
		tcp_echoserver_connection_close(ess->pcb, ess);
		ess = NULL;
	}
}

void StartReceivingModbusTCPIP(){

}
