/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/capturaDadosModbusBase.hpp>

capturaDadosModbusBase::capturaDadosModbusBase() :
    timer1BeginCallback(this, &capturaDadosModbusBase::timer1BeginCallbackHandler),
    timer1TickCallback(this, &capturaDadosModbusBase::timer1TickCallbackHandler)
{
    setWidth(480);
    setHeight(272);
    timer1.setXY(0, 0);
    timer1.setVisible(false);
    timer1.setBeginCallback(timer1BeginCallback);
    timer1.setTickCallback(timer1TickCallback);

    add(timer1);
}

void capturaDadosModbusBase::initialize()
{
    timer1.initialize();
}

void capturaDadosModbusBase::timer1BeginCallbackHandler()
{
    //BeginTimer
    //When timer1 begin execute C++ code
    //Execute C++ code
    flag_recuperar_leitura_dig = false;
    
    ReadWriteModbus485(553, 0, _INT_, REPEAT);
    ReadWriteModbus485(554, 0, _INT_, REPEAT);
    ReadWriteModbus485(555, 0, _INT_, REPEAT);
    ReadWriteModbus485(556, 0, _INT_, REPEAT);
    
    timer1.setWaitTime(250);
    timer1.start();
}

void capturaDadosModbusBase::timer1TickCallbackHandler()
{
    //Tick
    //When timer1 tick execute C++ code
    //Execute C++ code
    if (flag_recuperar_leitura_dig)
    {
    	ReadWriteModbus485(553, 0, _INT_, REPEAT);
    	ReadWriteModbus485(554, 0, _INT_, REPEAT);
    	ReadWriteModbus485(555, 0, _INT_, REPEAT);
    	ReadWriteModbus485(556, 0, _INT_, REPEAT);
    	Wait(50);
    
    	flag_recuperar_leitura_dig = false;
    }
    else
    {
    	W_1_4553 = (int)(ReadBufferModbus485(553));	// valor lido da dig1 do controlador
    	W_1_4554 = (int)(ReadBufferModbus485(554));	// valor lido da dig2 do controlador
    	W_1_4555 = (int)(ReadBufferModbus485(555));	// valor lido da dig3 do controlador
    	W_1_4556 = (int)(ReadBufferModbus485(556));	// valor lido da dig4 do controlador	
    }
}

