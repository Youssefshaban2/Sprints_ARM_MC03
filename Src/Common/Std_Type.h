#ifndef Data_Type_
#define Data_Type_
typedef unsigned char uint8;        //1byte * 8bits=  8 bits
typedef unsigned short int uint16;  //2byte * 8bits=  16 bits
typedef unsigned long int uint32;   //4byte * 8bits = 32 bits

typedef signed char sint8;          //1byte * 8bits=  8 bits
typedef signed short int sint16;    //2byte * 8bits=  16 bits
typedef signed long int sint32;     //4byte * 8bits = 32 bits

typedef float float32;               //4byte * 8bits = 32 bits
typedef double float64;              //8byte * 8bits = 64 bits
typedef long double float96;         //12byte * 8bits = 96 bits


typedef enum{
    False,
    True
}bool;

#endif
