/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  dio.c
 *        \brief  Module
 *
 *      \details  Dio driver
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "dio.h"
#include "../BitMath.h"
#include "../mcu_hw.h"
#include "../Std_Type.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : uint8 Dio_ReadPIN(PIN_Type Pin_Name)        
* \Description     : Read PIN Data                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Pin_Name   Name Of The PIN(A0,A1,A2)                     
* \Parameters (out): Result                                                      
* \Resulturn value:   : uint8
*                                                                      
*******************************************************************************/
uint8 Dio_ReadPIN(Pins Pin_Name)
{
    uint8 Result;
    Ports Port_Name = Pin_Name / 8;
    Pins Pin_Pos = Pin_Name % 8;
    switch(Port_Name)
    {
    case Port_A:
        Result = Get_Bit(PORTA_REG.GPIODATA,Pin_Pos); break;
    case Port_B:
        Result = Get_Bit(PORTB_REG.GPIODATA,Pin_Pos); break;
    case Port_C:
        Result = Get_Bit(PORTC_REG.GPIODATA,Pin_Pos); break;
    case Port_D:
        Result = Get_Bit(PORTD_REG.GPIODATA,Pin_Pos); break;
    case Port_E:
        Result = Get_Bit(PORTE_REG.GPIODATA,Pin_Pos); break;
    case Port_F:
        Result = Get_Bit(PORTF_REG.GPIODATA,Pin_Pos); break;
    }
    return Result;
}
/*************************************END OF FUNCTION********************************************/

/******************************************************************************
* \Syntax          : Dio_WritePIN(Pins Pin_Name, uint8 Dir)       
* \Description     : Write On Choosen Pin High Or Low                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : PIN_Id  , Dir(HIGH,LOW)                    
* \Parameters (out): Null                                                     
* \Resulturn value:   : Null
*                                                                      
*******************************************************************************/
void Dio_WritePIN(Pins Pin_Name, uint8 Dir)
{
    Ports Port_Name = Pin_Name / 8;
    Pins Pin_Pos = Pin_Name % 8;
    switch(Port_Name)
    {
    case Port_A:
        if(Dir == Low){
            CLR_BIT(PORTA_REG.GPIODATA,Pin_Pos);
        }
        else { 
            SET_BIT(PORTA_REG.GPIODATA,Pin_Pos);
        } 
        break;
    case Port_B:
        if(Dir == Low) { 
            CLR_BIT(PORTB_REG.GPIODATA,Pin_Pos);
            }
        else { SET_BIT(PORTB_REG.GPIODATA,Pin_Pos);
        }
        break;
    case Port_C:
        if(Dir == Low) {
            CLR_BIT(PORTC_REG.GPIODATA,Pin_Pos);
        }
        else {
            SET_BIT(PORTC_REG.GPIODATA,Pin_Pos);
            }
        break;
    case Port_D:
        if(Dir == Low) {
            CLR_BIT(PORTD_REG.GPIODATA,Pin_Pos);
        }
        else { 
            SET_BIT(PORTD_REG.GPIODATA,Pin_Pos);
            }
        break;
    case Port_E:
        if(Dir == Low) { 
            CLR_BIT(PORTE_REG.GPIODATA,Pin_Pos);
        }
        else {
            SET_BIT(PORTE_REG.GPIODATA,Pin_Pos);
        }
        break;
    case Port_F:
        if(Dir == Low) {
            CLR_BIT(PORTF_REG.GPIODATA,Pin_Pos);
        }
        else { 
            SET_BIT(PORTF_REG.GPIODATA,Pin_Pos);
        }
        break;
    }
}
/*************************************END OF FUNCTION********************************************/

/******************************************************************************
* \Syntax          : Dio_ReadPort(Ports Port_Name)       
* \Description     : Read Whole Port                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Port_Name                  
* \Parameters (out): Result                                                     
* \Resulturn value:   : uint8
*                                                                      
*******************************************************************************/
uint8 Dio_ReadPort(Ports Port_Name)
{
    uint8 Result;
    switch(Port_Name)
    {
    case Port_A:
        Result = PORTA_REG.GPIODATA; break;
    case Port_B:
        Result = PORTB_REG.GPIODATA; break;
    case Port_C:
        Result = PORTC_REG.GPIODATA; break;
    case Port_D:
        Result = PORTD_REG.GPIODATA; break;
    case Port_E:
        Result = PORTE_REG.GPIODATA; break;
    case Port_F:
        Result = PORTF_REG.GPIODATA; break;
    }
    return Result;
}
/*************************************END OF FUNCTION********************************************/

/******************************************************************************
* \Syntax          : Dio_WritePort(Ports Port_Name, uint8 value)       
* \Description     : Write On Given Port High Or Low                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Port_Name , Value(uint8 value =  0b00000110)               
* \Parameters (out): Null                                                  
* \Resulturn value:   : Null
*                                                                      
*******************************************************************************/
void Dio_WritePort(Ports Port_Name, uint8 value)
{
    switch(Port_Name)
    {
    case Port_A: 
        PORTA_REG.GPIODATA = value; break;
    case Port_B:
        PORTB_REG.GPIODATA = value; break;
    case Port_C:
        PORTC_REG.GPIODATA = value; break;
    case Port_D:
        PORTD_REG.GPIODATA = value; break;
    case Port_E:
        PORTE_REG.GPIODATA = value; break;
    case Port_F:
        PORTF_REG.GPIODATA = value; break;
    }
}
/*************************************END OF FUNCTION********************************************/

/******************************************************************************
* \Syntax          : Dio_TogglePin(Pins Pin_Name)      
* \Description     : Flip Pin From HIGH TO LOW OR LOW TO HIGH                                 
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Pin_Name (A0,A1,B0)etc              
* \Parameters (out): Null                                                  
* \Resulturn value:   : Null
*                                                                      
*******************************************************************************/
void Dio_TogglePin(Pins Pin_Name)
{
    Ports Port_Name = Pin_Name / 8;
    Pins Pin_Pos = Pin_Name % 8;
    switch(Port_Name)
    {
    case Port_A:
        TOGGLE_BIT(PORTA_REG.GPIODATA,Pin_Pos); break;
    case Port_B:
        TOGGLE_BIT(PORTB_REG.GPIODATA,Pin_Pos);break;
    case Port_C:
        TOGGLE_BIT(PORTC_REG.GPIODATA,Pin_Pos); break;
    case Port_D:
        TOGGLE_BIT(PORTD_REG.GPIODATA,Pin_Pos); break;
    case Port_E:
        TOGGLE_BIT(PORTE_REG.GPIODATA,Pin_Pos); break;
    case Port_F:
        TOGGLE_BIT(PORTF_REG.GPIODATA,Pin_Pos); break;
    }
}
/*************************************END OF FUNCTION********************************************/

/**********************************************************************************************************************
 *  END OF FILE: dio.c
 *********************************************************************************************************************/