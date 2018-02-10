
#include "../include/operands.h"
#include "../include/registers.h"

extern short registers[ ];

short *GetOperand( const char *name )
{
    RegisterMap map[ ] = 
    { 
        {"AX", 0 }, 
        {"BX", 1 }, 
        {"CX", 2 }, 
        {"DX", 3 }, 
        {"SS", 4 }, 
        {"SP", 5 }, 
        {"BP", 6 }, 
        {"FLAGS", -1 },//o flag nao podera ser acessadi diretamente
        {NULL, -1 } 
    };
    
    RegisterMap *ptr_map = map;
    
    static short imediate = 0;
    
    if( name )
    {
    
        if( isalpha( *name ) )
        {
            
            while( ptr_map->name )
            {
                if( !strcmp( name , ptr_map->name ) )
                {
                    return &registers[ ptr_map->index];
                }
                
                ptr_map++;
            }
            
        }
        
        else if( isdigit( *name ) )
        {
            
            imediate = atoi(name);
            
            return &imediate;
        }
    }
    
    return NULL;
    
}