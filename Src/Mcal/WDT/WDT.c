/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  WDT.c
 *        \brief  Initialization of WatchDog Timer
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
#include "WDT.h"
#include "../Config/WDT_cfg.h"
#include "WDT_Types.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
//GET SYSTEMCLOCK
extern volatile uint32 GlobalSystemClock;

//Prototype Of The Input Data
const extern Wdg_Config WDT_Config_1 ={Notification_Enabled,Standard_Int,200,500};
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void WDT_init(const Wdg_Config *WdgPtr)        
* \Description     : initialization of WatchDogTimer                                   
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : *WdgPtr    pointer to struct                     
* \Parameters (out): void                                                      
* \Return value:   : void                                 
*******************************************************************************/
void WDT_init(const Wdg_Config *WdgPtr)
{
    Notification_Handler    LocalNotify;
    InterruptType           LocalInt;
    InitialTimeout          LocalInitTimeOut;
    MaxTimeout              LocalMaxTimeOut;

    LocalNotify     =       WdgPtr->notification_handler;
    LocalInt        =       WdgPtr->interrupt_type;
    LocalInitTimeOut=       WdgPtr->intial_timeout;
    LocalMaxTimeOut =       WdgPtr->max_timeout;

    //Loading the Value Then Converting it to ms
    LocalInitTimeOut *=GlobalSystemClock;
    WDTLOAD_REG.WDT_Reg = LocalInitTimeOut;
    //Wait for WRC Bit to Be Set (First Timeout)
    while (WDTCTL_REG.WDT_bits.B31 = 0);
    //Set Reset Enable in WDCTL
    Set_Bit(WDTCTL_REG.WDT_Reg,1);
    //Wait for WRC Bit to Be Set (Second Timeout)
    while (WDTCTL_REG.WDT_bits.B31 = 0);
    //Set Interrupt
    if (LocalInt == Standard_Int){
        Clr_Bit(WDTCTL_REG.WDT_Reg,2);
    }
    else{
        Set_Bit(WDTCTL_REG.WDT_Reg,2);
    }
    //Lock WDT
    WDTLOCK_REG.WDT_Reg =1;
}

/******************************************************************************
* \Syntax          : Wdt_SetTriggerCondition(uint16 timeout)        
* \Description     : Set other Condition for the wdt or Refresh it                                  
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : uint16 timeout                    
* \Parameters (out): void                                                      
* \Return value:   : void                                 
*******************************************************************************/
void Wdt_SetTriggerCondition(uint16 timeout){
    //Unlock the WDTLOCK
    WDTLOCK_REG.WDT_Reg = 0x1ACCE551;
    //Load the New Value
    timeout *=GlobalSystemClock;
    WDTLOAD_REG.WDT_Reg = timeout;
    //Lock WDT
    WDTLOCK_REG.WDT_Reg =1;
}

/**********************************************************************************************************************
 *  END OF FILE: WDT.c
 *********************************************************************************************************************/