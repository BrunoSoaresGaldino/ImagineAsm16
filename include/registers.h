
#ifndef REGISTERS_H
#define REGISTERS_H

#include <stdlib.h>
#include <stdbool.h>

enum  registers{ AX, BX , CX , DX, SS, SP, BP };

typedef struct                  
{                               
    char *name;                 
    short index;
    
} RegisterMap;

bool IsRegister( short *operand );


#endif