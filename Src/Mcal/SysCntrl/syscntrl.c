/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  syscntrl.c
 *        \brief  Configure Overall Operations Of The System
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
#include "syscntrl.h"
#include "../Config/syscntrl_cfg.h"
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : void SysCntrl_init(void)        
* \Description     : Initialize Basic Para. Of The System                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : Null                     
* \Parameters (out): Null                                                      
* \Return value:   : Void                                  
*******************************************************************************/
void SysCntrl_init(void)
{
    //Initialize GPIO Ports
    RCGCGPIO_REG.B0 = RCGC_PORTA; //Port_A
    RCGCGPIO_REG.B1 = RCGC_PORTA; //Port_B
    RCGCGPIO_REG.B2 = RCGC_PORTA; //Port_C
    RCGCGPIO_REG.B3 = RCGC_PORTA; //Port_D
    RCGCGPIO_REG.B4 = RCGC_PORTA; //Port_E
    RCGCGPIO_REG.B5 = RCGC_PORTA; //Port_F

    //Initialize UART Ports
    RCGCUART_REG.B0 = RCGC_UART0; //U0Rx & U0Tx
    RCGCUART_REG.B1 = RCGC_UART1; //U1Rx & U1Tx
    RCGCUART_REG.B2 = RCGC_UART2; //U2Rx & U2Tx
    RCGCUART_REG.B3 = RCGC_UART3; //U3Rx & U3Tx
    RCGCUART_REG.B4 = RCGC_UART4; //U4Rx & U4Tx
    RCGCUART_REG.B5 = RCGC_UART5; //U5Rx & U5Tx
    RCGCUART_REG.B6 = RCGC_UART6; //U6Rx & U6Tx
    RCGCUART_REG.B7 = RCGC_UART7; //U7Rx & U7Tx

    //Initialize SSI
    RCGCSSI_REG.B0 = RCGC_SSI0; //SSI0
    RCGCSSI_REG.B1 = RCGC_SSI0; //SSI1
    RCGCSSI_REG.B2 = RCGC_SSI0; //SSI2
    RCGCSSI_REG.B3 = RCGC_SSI0; //SSI3

    //Initialize I2C
    RCGCI2C_REG.B0 = RCGC_I2C0; //I2C0
    RCGCI2C_REG.B1 = RCGC_I2C1; //I2C1
    RCGCI2C_REG.B2 = RCGC_I2C2; //I2C2
    RCGCI2C_REG.B3 = RCGC_I2C3; //I2C3

    //Initialize CAN
    RCGCCAN_REG.B0 = RCGC_CAN0; //CAN0Rx & CAN0Tx
    RCGCCAN_REG.B1 = RCGC_CAN1; //CAN1Rx & CAN1Tx

    //Initialize ADC
    RCGCADC_REG.B0 = RCGC_ADC0; //ADC0
    RCGCADC_REG.B1 = RCGC_ADC1; //ADC1

    //Initialize PWM
    RCGCPWM_REG.B0 = RCGC_PWM0; //PWM0
    RCGCPWM_REG.B1 = RCGC_PWM1; //PWM1

    //Initialize WatchDogTimer
    RCGCWD_REG.B0 = RCGC_WDT0; //WDT0
    RCGCWD_REG.B1 = RCGC_WDT1; //WDT1
    
    //Initialize Timer
    RCGCTIMER_REG.B0 = RCGC_TIMER0; //Timer0
    RCGCTIMER_REG.B1 = RCGC_TIMER1; //Timer1
    RCGCTIMER_REG.B2 = RCGC_TIMER2; //Timer2
    RCGCTIMER_REG.B3 = RCGC_TIMER3; //Timer3
    RCGCTIMER_REG.B4 = RCGC_TIMER4; //Timer4
    RCGCTIMER_REG.B5 = RCGC_TIMER5; //Timer5
}

/**********************************************************************************************************************
 *  END OF FILE: syscntrl.c
 *********************************************************************************************************************/