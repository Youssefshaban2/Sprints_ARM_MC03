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
#include "../Std_Type.h"
#include "../BitMath.h"
#include "nvic.h"
#include "../../Config/nvic_cfg.h"
#include "../mcu_hw.h"

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
    //In Vector Table We Define GPIOx
    NVIC_REG.EN0.B0 =   NVIC_GPIO_A;        //GPIOA-> Bit0
    NVIC_REG.EN0.B1 =   NVIC_GPIO_B;        //GPIOB-> Bit1
    NVIC_REG.EN0.B2 =   NVIC_GPIO_C;        //GPIOC-> Bit2
    NVIC_REG.EN0.B3 =   NVIC_GPIO_D;        //GPIOD-> Bit3
    NVIC_REG.EN0.B4 =   NVIC_GPIO_E;        //GPIOE-> Bit4
    NVIC_REG.EN0.B30 =  NVIC_GPIO_F;        //GPIOF-> Bit30

    //In Vector Table We Define UARTx
    NVIC_REG.EN0.B5 =   NVIC_UART0;         //UART0-> Bit5
    NVIC_REG.EN0.B6 =   NVIC_UART1;         //UART1-> Bit6
    NVIC_REG.EN1.B1 =   NVIC_UART2;         //UART2-> Bit33
    NVIC_REG.EN1.B27 =  NVIC_UART3;         //UART3-> Bit59
    NVIC_REG.EN1.B28 =  NVIC_UART4;         //UART4-> Bit60
    NVIC_REG.EN1.B29 =  NVIC_UART5;         //UART5-> Bit61
    NVIC_REG.EN1.B30 =  NVIC_UART6;         //UART6-> Bit62
    NVIC_REG.EN1.B31 =  NVIC_UART7;         //UART7-> Bit63

    //In Vector Table We Define SPI
    NVIC_REG.EN0.B7 =   NVIC_SSI0;          //SPI0-> Bit7
    NVIC_REG.EN1.B2 =   NVIC_SSI1;          //SPI1-> Bit34
    NVIC_REG.EN1.B25 =  NVIC_SSI2;          //SPI2-> Bit57
    NVIC_REG.EN1.B26 =  NVIC_SSI3;          //SPI3-> Bit58

    //In Vector Table We Define I2C
    NVIC_REG.EN0.B8 =   NVIC_I2C0;          //I2C-> Bit8
    NVIC_REG.EN1.B5 =   NVIC_I2C1;          //I2C-> Bit37
    NVIC_REG.EN3.B4 =   NVIC_I2C2;          //I2C-> Bit68
    NVIC_REG.EN4.B5 =   NVIC_I2C3;          //I2C-> Bit69

    //In Vector Table We Define WDT
    NVIC_REG.EN0.B18 =  NVIC_GWDT;           //WDT->Bit18
    

}

/**********************************************************************************************************************
 *  END OF FILE: nvic.c
 *********************************************************************************************************************/