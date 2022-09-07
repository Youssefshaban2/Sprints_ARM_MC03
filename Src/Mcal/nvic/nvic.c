/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  nvic.c
 *        \brief  Initialize NVIC Driver
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "./Std_Type.h"
#include "./BitMath.h"
#include "nvic.h"
#include "././Config/nvic_cfg.h"
#include "mcu_hw.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void NVIC_init(void)      
* \Description     : Initialize NVIC Module                            
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None                                
*******************************************************************************/
void NVIC_init(void)
{
    //in vector table from bit0 to bit4 is GPIOx
    NVIC_REG.EN0.B0 = Disable;  //GPIOA
    NVIC_REG.EN0.B1 = Disable;  //GPIOB
    NVIC_REG.EN0.B2 = Disable;  //GPIOC
    NVIC_REG.EN0.B3 = Disable;  //GPIOD
    NVIC_REG.EN0.B4 = Disable;  //GPIOE	
}

/**********************************************************************************************************************
 *  END OF FILE: nvic.c
 *********************************************************************************************************************/