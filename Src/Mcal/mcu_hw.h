/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  mcu_hw
 *       Module:  
 *
 *  Description:  define pins   
 *  
 *********************************************************************************************************************/
#ifndef mcu_hw_H
#define mcu_hw_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "./Std_Type.h"
#include "./BitMath.h"

/*************************
NVIC Registers
//Base Adrr: 0xE000E000
**************************/

#define NVIC_REG (*((volatile NVIC_Reg_Name*)0xE000E100))

typedef struct 
{
    NVIC_Bits EN0;
    NVIC_Bits EN1;
    NVIC_Bits EN2;
    NVIC_Bits EN3;
    NVIC_Bits EN4;
}NVIC_Reg_Name;

typedef struct
{
    uint32 B0:1;
    uint32 B1:1;
    uint32 B2:1;
    uint32 B3:1;
    uint32 B4:1;
    uint32 B5:1;
    uint32 B6:1;
    uint32 B7:1;
    uint32 B8:1;
    uint32 B9:1;
    uint32 B10:1;
    uint32 B11:1;
    uint32 B12:1;
    uint32 B13:1;
    uint32 B14:1;
    uint32 B15:1;
    uint32 B16:1;
    uint32 B17:1;
    uint32 B18:1;
    uint32 B19:1;
    uint32 B20:1;
    uint32 B21:1;
    uint32 B22:1;
    uint32 B23:1;
    uint32 B24:1;
    uint32 B25:1;
    uint32 B26:1;
    uint32 B27:1;
    uint32 B28:1;
    uint32 B29:1;
    uint32 B30:1;
    uint32 B31:1;
}NVIC_Bits;

/*************************
GPIO Registers
//Base Addr: 0x40004000
**************************/

#define PORTA_REG     (*((volatile PORT_RegType*)0x400043FC)) 
#define PORTB_REG     (*((volatile PORT_RegType*)0x400053FC))
#define PORTC_REG     (*((volatile PORT_RegType*)0x400063FC))
#define PORTD_REG     (*((volatile PORT_RegType*)0x400073FC))
#define PORTE_REG     (*((volatile PORT_RegType*)0x400243FC))
#define PORTF_REG     (*((volatile PORT_RegType*)0x400253FC))

typedef struct
{
    uint32 GPIODATA;
    uint32 GPIODIR;
    uint32 GPIOIS;
    uint32 GPIOIBE;
    uint32 GPIOIEV;
    uint32 GPIOIM;
    uint32 GPIORIS;
    uint32 GPIOMIS;
    uint32 GPIOICR;
    uint32 GPIOAFSEL;
    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R;
    uint32 GPIODR4R;
    uint32 GPIODR8R;
    uint32 GPIOODR;
    uint32 GPIOPUR;
    uint32 GPIOPDR;
    uint32 GPIOSLR;
    uint32 GPIODEN;
    uint32 GPIOLOCK;
    uint32 GPIOCR;
    uint32 GPIOAMSEL;
    uint32 GPIOPCTL;
    uint32 GPIOADCCTL;
    uint32 GPIODMACTL;
}PORT_RegType;

/*************************
SysControl & RCGC Registers
//Base Addr: 0x400FE000
**************************/

#define RCGCGPIO_REG            (*((volatile RCGC_RegType*)(0x400FE000+0x608)))
#define RCGCUART_REG            (*((volatile RCGC_RegType*)(0x400FE000+0x618)))
#define RCGCSSI_REG             (*((volatile RCGC_RegType*)(0x400FE000+0x61C)))
#define RCGCI2C_REG             (*((volatile RCGC_RegType*)(0x400FE000+0x620)))
#define RCGCCAN_REG             (*((volatile RCGC_RegType*)(0x400FE000+0x634)))
#define RCGCADC_REG             (*((volatile RCGC_RegType*)(0x400FE000+0x638)))
#define RCGCPWM_REG             (*((volatile RCGC_RegType*)(0x400FE000+0x640)))
#define RCGCWD_REG              (*((volatile RCGC_RegType*)(0x400FE000+0x600)))
#define RCGCTIMER_REG           (*((volatile RCGC_RegType*)(0x400FE000+0x604)))

typedef struct{
    uint32 B0:1;
    uint32 B1:1;
    uint32 B2:1;
    uint32 B3:1;
    uint32 B4:1;
    uint32 B5:1;
    uint32 B6:1;
    uint32 B7:1;
}RCGC_RegType;

/*************************
    WatchDog Timer(1)
//Base Addr: 0x40001000
**************************/

#define WDTLOAD_REG             (*((volatile WDT_RegType *)(0x40001000+0x000)))
#define WDTVALUE_REG            (*((volatile WDT_RegType *)(0x40001000+0x004)))
#define WDTCTL_REG              (*((volatile WDT_RegType *)(0x40001000+0x008)))
#define WDTICR_REG              (*((volatile WDT_RegType *)(0x40001000+0x00C)))
#define WDTRIS_REG              (*((volatile WDT_RegType *)(0x40001000+0x010)))
#define WDTMIS_REG              (*((volatile WDT_RegType *)(0x40001000+0x014)))
#define WDTTEST_REG             (*((volatile WDT_RegType *)(0x40001000+0x418)))
#define WDTLOCK_REG             (*((volatile WDT_RegType *)(0x40001000+0xC00)))

typedef union 
{
    struct
    {
        uint32 B0:1;
        uint32 B1:1;
        uint32 B2:1;
        uint32 B3:1;
        uint32 B4:1;
        uint32 B5:1;
        uint32 B6:1;
        uint32 B7:1;
        uint32 B8:1;
        uint32 B9:1;
        uint32 B10:1;
        uint32 B11:1;
        uint32 B12:1;
        uint32 B13:1;
        uint32 B14:1;
        uint32 B15:1;
        uint32 B16:1;
        uint32 B17:1;
        uint32 B18:1;
        uint32 B19:1;
        uint32 B20:1;
        uint32 B21:1;
        uint32 B22:1;
        uint32 B23:1;
        uint32 B24:1;
        uint32 B25:1;
        uint32 B26:1;
        uint32 B27:1;
        uint32 B28:1;
        uint32 B29:1;
        uint32 B30:1;
        uint32 B31:1;
    }WDT_bits;

    uint32 WDT_Reg;
}WDT_RegType;



#endif  /* mcu_hw_H */

/**********************************************************************************************************************
 *  END OF FILE: mcu_hw.h
 *********************************************************************************************************************/