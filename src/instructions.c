
#include "../include/instructions.h"


extern short registers[ ];

void MOV( short *destiny, short *source  )
{

    if( destiny && source )
    {
        if( IsRegister( destiny ) )
        {
            *destiny = *source;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

void ADD( short *operand1, short *operand2 )
{
    if( operand1 && operand2  )
    {
        if( IsRegister( operand1 ) )
        {
            
            *operand1 += *operand2;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }        
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
    
}

void SUB( short *operand1, short *operand2 )
{
    if( operand1 && operand2 )
    {
        if( IsRegister( operand1 ) )
        {
            
            *operand1 -= *operand2;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

void MUL( short *operand1, short *operand2 )
{
    if( operand1 && operand2  )
    {
        if( IsRegister( operand1 ) )
        {
            
            *operand1 *= *operand2;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

void DIV( short *operand1, short *operand2 )
{
    if( operand1 && operand2  )
    {
        if( *operand2 )
        {
            
            if( IsRegister( operand1 ) )
            {
            
                *operand1 /= *operand2;
            }
            else
            {
                AbortOnError( INVALID_LEFT_OPERAND );
            }
            
        }
        else
        {
            AbortOnError( DIVISION_BY_ZERO );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
 
}

void NEG( short *operand )
{
    if ( operand )
    {
        if( IsRegister( operand ) )
        {
            
            *operand  =  - *operand;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

void INC( short *operand )
{
    if ( operand )
    {
        if( IsRegister( operand ) )
        {
            
            ( *operand )++;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

void DEC( short *operand )
{
    if ( operand )
    {
        if( IsRegister( operand ) )
        {
            
            ( *operand )--;
        }
        else
        {
            AbortOnError( INVALID_LEFT_OPERAND );
        }
    }
    else
    {
        AbortOnError( NULL_OPERAND );
    }
    
}

int REP( char **tokens )
{
    
    void (*instruction)( void * , void * , void *);// ponteiro para executar a instrução
    
    short *operands[3];// array que conterá os endereços dos argumentos usado na execução da instrução
    
    int param_required = 0;// para saber quantos parametros a função requere

    int i;// para utilizar em iterações
    
    char **ptr_tokens = tokens;// ponteiro auxiliar, para iterar sobre o array de tokens
    
    if( ( instruction = GetInstruction( *ptr_tokens ) ) )
    {
        
        param_required = ParamRequired( instruction );
        
        ptr_tokens++;
   
        
    }
    
    i = 0;
    
    if( param_required == -1 )
    {
        AbortOnError( INVALID_OPERATION );
    }
    
    while( param_required-- )
    {
        
        if( ( operands[ i++ ] =  GetOperand( *ptr_tokens ) ) )
        {
            ptr_tokens++;
        }
        else
        {
            AbortOnError( OPERAND_MISSING );
        }
        
    }
  
  
    while( registers[ CX ]-- )
    {

        
        instruction( operands[0], operands[1] , operands [ 3 ]  );
       
    }
    
    
    return i+1;
    
    
}

void *GetInstruction( const char *name )
{
    InstructionMap map[ ] = 
    { 
        {"MOV",MOV}, 
        {"ADD",ADD},
        {"SUB",SUB},
        {"MUL",MUL},
        {"DIV",DIV},
        {"NEG",NEG},
        {"INC",INC},
        {"DEC",DEC},
        {"REP",REP},
        {NULL,NULL} 
    };
    
    InstructionMap *ptr_map = map;
    
    while( ptr_map->name )
    {
        if( !strcmp( name , ptr_map->name ) )
        {
           return ptr_map->func;
        }
        
        ptr_map++;
    }
    
    return NULL;
    
}
int ParamRequired( void *func )
{
    
    if( func == REP )
    {
        return -1;
    }
    
    if( func == NEG || func == INC || func == DEC  )
    {
        return 1;
    }

    
    return 2;
    
}