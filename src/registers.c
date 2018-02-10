
#include "../include/registers.h"

short registers[10];

bool IsRegister( short *operand )
{
    
    return(  operand >= registers && operand <= registers + sizeof( registers ) * sizeof( int ) );
    
}