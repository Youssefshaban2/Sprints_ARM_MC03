#ifndef MACROS_bit_
#define MACROS_bit_

#define set_bit(reg,bit)  (reg |= (1<<bit))
#define clr_bit(reg,bit)  (reg &= ~(1<<bit))
#define toggle_bit(reg,bit)  (reg ^= (1<<bit))
#define get_bit(reg,bit)  ((reg>>(bit)) & 1)

#endif