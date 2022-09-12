#ifndef MACROS_bit_
#define MACROS_bit_

#define Set_Bit(reg,bit)  (reg |= (1<<bit))
#define Clr_Bit(reg,bit)  (reg &= ~(1<<bit))
#define Toggle_Bit(reg,bit)  (reg ^= (1<<bit))
#define Get_Bit(reg,bit)  ((reg>>(bit)) & 1)

#endif