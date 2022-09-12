/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  port.c
 *        \brief  Initialize ports config
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "../BitMath.h"
#include "../mcu_hw.h"
#include "../Std_Type.h"
#include "port.h"
#include "port_types.h"
#include "../Config/port_cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Port_config Port_config_arr[] = {
    {A0,Output,PORTA_PA0_U0Rx,Interrupt_Diabled,OpenDrain,_4mA},
    {A1,Output,DIO,Interrupt_Diabled,PullDownRes,_2mA},
    {A2,Input,PORTA_PA2_SSI0Clk,Interrupt_Diabled,PullUpRes,_8mA}
    };
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : Port_Init(void)        
* \Description     : initialization of ports and pins                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Null                     
* \Parameters (out): Null                                                      
* \Return value:   : Null                                  
*******************************************************************************/
void Port_Init(void)
{
    Port_Type Port_Name;
    Pins Pin_Num;
    
    volatile PORT_RegType *PortAddr;
    //Looping Around All 43 PINS
    for(uint8 i =0; i < 43;++i){
        Port_Name = i / 8; 
        Pin_Num = i % 8;

        switch (Port_Name)
        {
        case port_A:
            PortAddr = &PORTA_REG; break;
        case port_B:
            PortAddr = &PORTB_REG; break;
        case port_C:
            PortAddr = &PORTC_REG; break;
        case port_D:
            PortAddr = &PORTD_REG; break;
        case port_E:
            PortAddr = &PORTE_REG; break;
        case port_F:
            PortAddr = &PORTF_REG; break;
        }

        //Set Pins Direction Input Or Output
        if(Port_config_arr[i].dir == Output){
            //Output == 1
            Set_Bit(PortAddr->GPIODIR,Pin_Num);
        }
        else{
            //Input == 0
            Clr_Bit(PortAddr->GPIODIR,Pin_Num);
        }

        //Set Pins Mode
        //(Any Pin is a GPIO by Default To Select Any Mode You Have To Set GPIOAFSEL to 1)
        if (Port_config_arr[i].mode == DIO){
            //GPIOAFSEL = 1 (Just To Be Sure)
            Clr_Bit(PortAddr->GPIOAFSEL,Pin_Num);
        }
        else{
            //GPIOAFSEL = 1
            Set_Bit(PortAddr->GPIOAFSEL,Pin_Num);
            //Each 4 bits control 1 PIN So You Have to Multiply Pin no by 4
            PortAddr->GPIOPCTL |= ( Port_config_arr[i].mode << (Pin_Num*4) );
        }

        //Set Pins Interrupt Mode
        if(Port_config_arr[i].interrupt == Interrupt_Diabled){
            Clr_Bit(PortAddr->GPIOIM, Pin_Num); //GPIOIM == 0
        }
        else{
            Set_Bit(PORTA_REG.GPIOIM, Pin_Num); //GPIOIM == 1
            if(Port_config_arr[i].interrupt == Interrupt_RisingEdge || Port_config_arr[i].interrupt == Interrupt_High){
                //RisingEdge Or High Level = 1
                Set_Bit(PortAddr->GPIOIEV,Pin_Num);
            }
            else if(Port_config_arr[i].interrupt == Interrupt_FallingEdge || Port_config_arr[i].interrupt == Interrupt_Low){
                //FallingEdge Or Low Level = 0
                Clr_Bit(PortAddr->GPIOIEV,Pin_Num);
            }
            else if(Port_config_arr[i].interrupt == Interrupt_BothEdges){
                //Either High Level Or Low Level Will Cause An Interrupt
                Set_Bit(PortAddr->GPIOIBE,Pin_Num);
            }
        }

        //Set Attach Config
        if(Port_config_arr[i].attach == OpenDrain){
            Set_Bit(PortAddr->GPIOODR,Pin_Num);
        }
        else if(Port_config_arr[i].attached == PullUpRes){
            Set_Bit(PortAddr->GPIOPUR,Pin_Num);
        }
        else if(Port_config_arr[i].attached == PullDownRes){
            Set_Bit(PortAddr->GPIOPDR,Pin_Num);
        }

        //Set Current Mode
        if(Port_config_arr[i].current == _2mA)
        {
            Set_Bit(PortAddr->GPIODR2R,Pin_Num);
        }else if(Port_config_arr[i].current == _4mA)
        {
            Set_Bit(PortAddr->GPIODR4R,Pin_Num);
        }else if(Port_config_arr[i].current == _8mA)
        {
            Set_Bit(PortAddr->GPIODR8R,Pin_Num);
        }

        //set ADC Or Digital
        if(Port_config_arr[i].mode == Port_Mode_AIN){
            //Enable ADC
            Set_Bit(PortAddr->GPIOADCCTL,Pin_Num);
            Clr_Bit(PortAddr->GPIODEN,Pin_Num);
        }
        else{
            //Enable Digital
            Set_Bit(PortAddr->GPIODEN,Pin_Num);
            Clr_Bit(PortAddr->GPIOADCCTL,Pin_Num);
        }
         

    }
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/