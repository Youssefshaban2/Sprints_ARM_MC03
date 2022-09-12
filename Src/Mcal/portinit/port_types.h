#ifndef port_types_H
#define port_types_H

#include "../Std_Type.h"

//Define Pin Modes
#define DIO                       0
//PORTA
#define PORTA_PA0_U0Rx            1
#define PORTA_PA0_CAN1Rx          8

#define PORTA_PA1_U0Tx            1
#define PORTA_PA1_CAN1TX          8

#define PORTA_PA2_SSI0Clk         2

#define PORTA_PA3_SSI0Fss         2

#define PORTA_PA4_SSI0Rx          2

#define PORTA_PA5_SSI0Tx          2

#define PORTA_PA6_I2C1SCL         3
#define PORTA_PA6_M1PWM2          5

#define PORTA_PA7_I2C1SDA         3
#define PORTA_PA7_M1PWM3          5
//PORTB
#define PORTB_PB0_U1Rx            1
#define PORTB_PB0_T2CCP0          7

#define PORTB_PB1_U1Tx            1
#define PORTB_PB1_T2CCP1          7

#define PORTB_PB2_I2C0SCL         3
#define PORTB_PB2_T3CCP0          7

#define PORTB_PB3_I2C0SDA         3
#define PORTB_PB3_T3CCP1          7

#define PORTB_PB4_I2C0SDA         2
#define PORTB_PB4_M0PWM2          4
#define PORTB_PB4_T1CCP0          7
#define PORTB_PB4_CAN0Rx          8

#define PORTB_PB5_SSI2Fss         2
#define PORTB_PB5_M0PWM3          4
#define PORTB_PB5_T1CCP1          7
#define PORTB_PB5_CAN0Tx          8

#define PORTB_PB6_SSI2Rx          2
#define PORTB_PB6_M0PWM0          4
#define PORTB_PB6_T0CCP0          7

#define PORTB_PB6_SSI2Tx          2
#define PORTB_PB6_M0PWM1          4
#define PORTB_PB6_T0CCP1          7
//PORTC
#define PORTC_PC0_TCK_SWCLK       1
#define PORTC_PC0_T4CCP0          7

#define PORTC_PC1_TMS_SWDIO       1
#define PORTC_PC1_T4CCP1          7

#define PORTC_PC2_TDI             1
#define PORTC_PC2_T5CCP0          7

#define PORTC_PC3_TDO_SWO         1
#define PORTC_PC3_T5CCP1          7

#define PORTC_PC4_U4Rx            1
#define PORTC_PC4_U1Rx            2
#define PORTC_PC4_M0PWM6          4
#define PORTC_PC4_IDX1            6
#define PORTC_PC4_WT0CCP0         7
#define PORTC_PC4_U1RTS           8

#define PORTC_PC5_U4Tx            1
#define PORTC_PC5_U1Tx            2
#define PORTC_PC5_M0PWM7          4
#define PORTC_PC5_PhA1            6
#define PORTC_PC5_WT0CCP1         7
#define PORTC_PC5_U1CTS           8

#define PORTC_PC6_U3Rx            1
#define PORTC_PC6_PhB1            6
#define PORTC_PC6_WT1CCP0         7
#define PORTC_PC6_USB0EPEN        8

#define PORTC_PC7_U3Tx            1
#define PORTC_PC7_WT1CCP1         7
#define PORTC_PC7_USB0PFLT        8
//PORTD
#define PORTD_PC0_SSI3Clk         1
#define PORTD_PC0_SSI1Clk         2
#define PORTD_PC0_I2C3SCL         3
#define PORTD_PC0_M0PWM6          4
#define PORTD_PC0_M1PWM0          5
#define PORTD_PC0_WT2CCP0         7

#define PORTD_PC1_SSI3Fss         1
#define PORTD_PC1_SSI1Fss         2
#define PORTD_PC1_I2C3SDA         3
#define PORTD_PC1_M0PWM7          4
#define PORTD_PC1_M1PWM1          5
#define PORTD_PC1_WT2CCP1         7

#define PORTD_PC2_SSI3Rx         1
#define PORTD_PC2_SSI1Rx         2
#define PORTD_PC2_M0FAULT0       4
#define PORTD_PC2_WT3CCP0        7
#define PORTD_PC2_USB0EPEN       8

#define PORTD_PC3_SSI3Tx         1
#define PORTD_PC3_SSI1Tx         2
#define PORTD_PC3_IDX0           6
#define PORTD_PC3_WT3CCP1        7
#define PORTD_PC3_USB0PFLT       8

#define PORTD_PC4_U6Rx           1
#define PORTD_PC4_WT4CCP0        7

#define PORTD_PC5_U6Tx           1
#define PORTD_PC5_WT4CCP1        7

#define PORTD_PC6_U2Rx           1
#define PORTD_PC6_M0FAULT0       4
#define PORTD_PC6_PhA0           6
#define PORTD_PC6_WT5CCP0        7

#define PORTD_PC7_U2Tx           1
#define PORTD_PC7_PhB0           6
#define PORTD_PC7_WT5CCP1        7
#define PORTD_PC7_NMI            8
//PORTE
#define PORTE_PE0_U7Rx           1

#define PORTE_PE1_U7Tx           1

#define PORTE_PE4_U5Rx           1
#define PORTE_PE4_I2C2SCL        3
#define PORTE_PE4_M0PWM4         4
#define PORTE_PE4_M1PWM2         5
#define PORTE_PE4_CAN0Rx         8

#define PORTE_PE5_U5Tx           1
#define PORTE_PE5_I2C2SDA        3
#define PORTE_PE5_M0PWM5         4
#define PORTE_PE5_M1PWM3         5
#define PORTE_PE5_CAN0Tx         8
//PORTF
#define PORTF_PF0_U1RTS          1
#define PORTF_PF0_SSI1Rx         2
#define PORTF_PF0_CAN0Rx         3
#define PORTF_PF0_M1PWM4         5
#define PORTF_PF0_PhA0           6
#define PORTF_PF0_T0CCP0         7
#define PORTF_PF0_NMI            8
#define PORTF_PF0_C0o            9

#define PORTF_PF1_U1CTS          1
#define PORTF_PF1_SSI1Tx         2
#define PORTF_PF1_M1PWM5         5
#define PORTF_PF1_PhB0           6
#define PORTF_PF1_T0CCP1         7
#define PORTF_PF1_C1o            9
#define PORTF_PF1_TRD1           14

#define PORTF_PF2_SSI1Clk        2
#define PORTF_PF2_M0FAULT0       4
#define PORTF_PF2_M1PWM6         5
#define PORTF_PF2_T1CCP0         7
#define PORTF_PF2_TRD0           14

#define PORTF_PF3_SSI1Fss        2
#define PORTF_PF3_CAN0Tx         3
#define PORTF_PF3_M1PWM7         5
#define PORTF_PF3_T1CCP1         7
#define PORTF_PF3_TRCLK          14

#define PORTF_PF4_M1FAULT0       5
#define PORTF_PF4_IDX0           6
#define PORTF_PF4_T2CCP0         7
#define PORTF_PF4_USB0EPEN       8

/*******************************************************/
typedef struct
{
    Pins              pin;
    Direction_Type    dir;
    uint8             mode;
    Intrrupt_Ctr_Type interrupt;
    Attached_Type     attached;
    Current_Type      current;
}Port_config;

typedef enum{
    A0,
    A1,
    A2,
    A3,
    A4,
    A5,
    A6,
    A7,

    B0,
    B1,
    B2,
    B3,
    B4,
    B5,
    B6,
    B7,

    C0,
    C1,
    C2,
    C3,
    C4,
    C5,
    C6,
    C7,

    D0,
    D1,
    D2,
    D3,
    D4,
    D5,
    D6,
    D7,

    E0,
    E1,
    E2,
    E3,
    E4,
    E5,

    F0,
    F1,
    F2,
    F3,
    F4

}Pins;

typedef enum{
    Input,
    Output
}Direction_Type;

typedef enum{
    Interrupt_Diabled,
    Interrupt_RisingEdge,
    Interrupt_High,
    Interrupt_FallingEdge,
    Interrupt_Low,
    Interrupt_BothEdges
}Intrrupt_Ctr_Type;

typedef enum{
    OpenDrain,
    PullUpRes,
    PullDownRes
}Attached_Type;

typedef enum{
    _2mA,
    _4mA,
    _8mA
}Current_Type;

typedef enum{
    port_A,
    port_B,
    port_C,
    port_D,
    port_E,
    port_F
}Port_Type;

typedef enum{
    Port_Mode_AIN
}Port_Mode;


#endif