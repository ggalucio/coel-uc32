/*
 * tcp_client.c
 *
 *  Created on: 24 nov 2021
 *      Author: paoloc
 */

#include "../Inc/tcp_client.h"
#include "lwip/pbuf.h"
#include "lwip/tcp.h"
#include "stdio.h"
#include "string.h"

u8_t  recev_buf[50];
__IO uint32_t message_count=0;

u8_t   data[100];

struct tcp_pcb *echoclient_pcb;

/* ECHO protocol states */
enum echoclient_states
{
  ES_NOT_CONNECTED = 0,
  ES_CONNECTED,
  ES_RECEIVED,
  ES_CLOSING,
};

/* structure to be passed as argument to the tcp callbacks */
struct echoclient
{
  enum echoclient_states state; /* connection status */
  struct tcp_pcb *pcb;          /* pointer on the current tcp_pcb */
  struct pbuf *p_tx;            /* pointer on pbuf to be transmitted */
};

struct echoclient *es = NULL;

/* Private function prototypes -----------------------------------------------*/
static err_t tcp_echoclient_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
static void tcp_echoclient_connection_close(struct tcp_pcb *tpcb, struct echoclient * es);
static err_t tcp_echoclient_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
static void tcp_echoclient_send(struct tcp_pcb *tpcb, struct echoclient * es);
static err_t tcp_echoclient_connected(void *arg, struct tcp_pcb *tpcb, err_t err);

/* Private functions ---------------------------------------------------------*/

void tcp_echoclient_received(struct pbuf *p){
 	BYTE len = p->tot_len;
  	memset (modbusTcpIpTransceiver.RxBuffer, '\0', sizeof(char) * len);
  	memcpy(modbusTcpIpTransceiver.RxBuffer, (char *)p->payload, len);

  	//ethHandler.tes = es;

	if(modbusTCPIPComm.ReceiveClbk){
		modbusTCPIPComm.ReceiveClbk(modbusTcpIpTransceiver.RxBuffer, len);
		ResetTcpIpModbusTimer();
	}
}

BOOLEAN tcp_echoclient_send_data(BYTE* pData, WORD size){

	if(echoclient_pcb->keep_cnt == echoclient_pcb->keep_cnt_sent)
		return AT_FALSE;

	if(READ_MODBUSTCPIP_PERIPH_STATUS() == 0)
		return AT_FALSE;

	err_t err = tcp_write(echoclient_pcb, (uint8_t*)pData, size, TCP_WRITE_FLAG_COPY);

	if(err != ERR_OK)
		return AT_FALSE;

	/* now send */
	err = tcp_output(echoclient_pcb);

	if(err != ERR_OK)
		return AT_FALSE;

	modbusTCPIPComm.State = MB_TRANSMITTING;
	return AT_TRUE;
}

/**
  * @brief  Connects to the TCP echo server
  * @param  None
  * @retval None
  */
BOOLEAN tcp_echoclient_connect(void)
{
  BOOLEAN conn = AT_FALSE;

  ip_addr_t DestIPaddr;

  modbusTCPIPComm.Send = tcp_echoclient_send_data;

  /* create new tcp pcb */
  echoclient_pcb = tcp_new();

  if (echoclient_pcb != NULL)
  {
    IP4_ADDR( &DestIPaddr, 192, 168, 5, 11);

    /* connect to destination address/port */
    conn = tcp_connect(echoclient_pcb,&DestIPaddr, 502,tcp_echoclient_connected) == ERR_OK ? AT_TRUE : AT_FALSE;

    echoclient_pcb->so_options |= SOF_KEEPALIVE;	// Enable keep alive
    echoclient_pcb->keep_intvl = 1000;
  }
  else
  {
    /* deallocate the pcb */
    memp_free(MEMP_TCP_PCB, echoclient_pcb);
  }

  return conn;
}

/**
  * @brief Function called when TCP connection established
  * @param tpcb: pointer on the connection contol block
  * @param err: when connection correctly established err should be ERR_OK
  * @retval err_t: returned error
  */
static err_t tcp_echoclient_connected(void *arg, struct tcp_pcb *tpcb, err_t err)
{
  //struct echoclient *es = NULL;

	ethHandler.connAvailable = AT_FALSE;

  if (err == ERR_OK)
  {
    /* allocate structure es to maintain tcp connection informations */
    es = (struct echoclient *)mem_malloc(sizeof(struct echoclient));

    if (es != NULL)
    {
      es->state = ES_CONNECTED;
      es->pcb = tpcb;

      sprintf((char*)data, "sending tcp client message %d", (int)message_count);

      /* allocate pbuf */
      es->p_tx = pbuf_alloc(PBUF_TRANSPORT, strlen((char*)data) , PBUF_POOL);

      if (es->p_tx)
      {
        /* copy data to pbuf */
        pbuf_take(es->p_tx, (char*)data, strlen((char*)data));

        /* pass newly allocated es structure as argument to tpcb */
        tcp_arg(tpcb, es);

        /* initialize LwIP tcp_recv callback function */
        tcp_recv(tpcb, tcp_echoclient_recv);

        /* initialize LwIP tcp_sent callback function */
        tcp_sent(tpcb, tcp_echoclient_sent);

        /* initialize LwIP tcp_poll callback function */
        //tcp_poll(tpcb, tcp_echoclient_poll, 1);

        /* send data */
        //tcp_echoclient_send(tpcb,es);

        SET_MODBUSTCPIP_PERIPH_STATUS();

        ethHandler.connAvailable = AT_TRUE;

        return ERR_OK;
      }
    }
    else
    {
      /* close connection */
      tcp_echoclient_connection_close(tpcb, es);

      /* return memory allocation error */
      return ERR_MEM;
    }
  }
  else
  {
    /* close connection */
    tcp_echoclient_connection_close(tpcb, es);
  }
  return err;
}

/**
  * @brief tcp_receiv callback
  * @param arg: argument to be passed to receive callback
  * @param tpcb: tcp connection control block
  * @param err: receive error code
  * @retval err_t: retuned error
  */
static err_t tcp_echoclient_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
  struct echoclient *es;
  err_t ret_err;

  LWIP_ASSERT("arg != NULL",arg != NULL);

  es = (struct echoclient *)arg;

  /* if we receive an empty tcp frame from server => close connection */
  if (p == NULL)
  {
    /* remote host closed connection */
    es->state = ES_CLOSING;
    if(es->p_tx == NULL)
    {
       /* we're done sending, close connection */
       tcp_echoclient_connection_close(tpcb, es);
    }
    else
    {
      /* send remaining data*/
      tcp_echoclient_send(tpcb, es);
    }
    ret_err = ERR_OK;
  }
  /* else : a non empty frame was received from echo server but for some reason err != ERR_OK */
  else if(err != ERR_OK)
  {
    /* free received pbuf*/
    if (p != NULL)
    {
      pbuf_free(p);
    }
    ret_err = err;
  }
  else if(es->state == ES_CONNECTED)
  {
    /* increment message count */
    message_count++;

    /* Acknowledge data reception */
    tcp_recved(tpcb, p->tot_len);

    /*char data[p->tot_len];
    memcpy(data, (char*)p->payload, sizeof(char) * p->tot_len);
    printf("Ricevuti; %s\n", data);*/

    tcp_echoclient_received(p);

    pbuf_free(p);
    //tcp_echoclient_connection_close(tpcb, es);
    ret_err = ERR_OK;
  }

  /* data received when connection already closed */
  else
  {
    /* Acknowledge data reception */
    tcp_recved(tpcb, p->tot_len);

    /* free pbuf and do nothing */
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  return ret_err;
}

/**
  * @brief function used to send data
  * @param  tpcb: tcp control block
  * @param  es: pointer on structure of type echoclient containing info on data
  *             to be sent
  * @retval None
  */
static void tcp_echoclient_send(struct tcp_pcb *tpcb, struct echoclient * es)
{
  struct pbuf *ptr;
  err_t wr_err = ERR_OK;

  while ((wr_err == ERR_OK) &&
         (es->p_tx != NULL) &&
         (es->p_tx->len <= tcp_sndbuf(tpcb)))
  {

    /* get pointer on pbuf from es structure */
    ptr = es->p_tx;

    /* enqueue data for transmission */
    wr_err = tcp_write(tpcb, ptr->payload, ptr->len, 1);

    if (wr_err == ERR_OK)
    {
      /* continue with next pbuf in chain (if any) */
      es->p_tx = ptr->next;

      if(es->p_tx != NULL)
      {
        /* increment reference count for es->p */
        pbuf_ref(es->p_tx);
      }

      /* free pbuf: will free pbufs up to es->p (because es->p has a reference count > 0) */
      pbuf_free(ptr);
   }
   else if(wr_err == ERR_MEM)
   {
      /* we are low on memory, try later, defer to poll */
     es->p_tx = ptr;
   }
   else
   {
     /* other problem ?? */
   }
  }
}

/**
  * @brief  This function implements the tcp_sent LwIP callback (called when ACK
  *         is received from remote host for sent data)
  * @param  arg: pointer on argument passed to callback
  * @param  tcp_pcb: tcp connection control block
  * @param  len: length of data sent
  * @retval err_t: returned error code
  */
static err_t tcp_echoclient_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
  struct echoclient *es;

  LWIP_UNUSED_ARG(len);

  es = (struct echoclient *)arg;

  if(es->p_tx != NULL)
  {
    /* still got pbufs to send */
    //tcp_echoclient_send(tpcb, es);
  }

  modbusTCPIPComm.State = MB_TRANSMITTED;
  return ERR_OK;
}

/**
  * @brief This function is used to close the tcp connection with server
  * @param tpcb: tcp connection control block
  * @param es: pointer on echoclient structure
  * @retval None
  */
static void tcp_echoclient_connection_close(struct tcp_pcb *tpcb, struct echoclient * ec )
{
	RESET_MODBUSTCPIP_PERIPH_STATUS();
	ethHandler.connAvailable = AT_FALSE;

	/* remove callbacks */
	tcp_recv(tpcb, NULL);
	tcp_sent(tpcb, NULL);
	tcp_poll(tpcb, NULL,0);

	if (ec != NULL)
	{
		if(ec->p_tx){
			pbuf_free(ec->p_tx);
			ec->p_tx = NULL;
		}

		mem_free(ec);
	}

	tcp_abort(tpcb);

	/* close tcp connection */
	tcp_close(tpcb);
}

BOOLEAN InitModbusTcpIpClient(){
	DeInitModbusTcpIpClient();
	return tcp_echoclient_connect();
}

void DeInitModbusTcpIpClient(){
	tcp_echoclient_connection_close(echoclient_pcb, es);
	memp_free(MEMP_TCP_PCB, echoclient_pcb);
	es = NULL;
}
