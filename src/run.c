
#include "../include/run.h"

void Run( char **tokens )
{
    int (*instruction)( void * , void * , void *);// ponteiro para executar a instrução
    
    short *operands[3];// array que conterá os endereços dos argumentos usado na execução da instrução
    
    int param_required = 0;// para saber quantos parametros a função requere

    int i;// para utilizar em iterações
    
    char **ptr_tokens = tokens;// ponteiro auxiliar, para iterar sobre o array de tokens
    
    while( *ptr_tokens )
    {    
        param_required = 0;
        
        if( ( instruction = GetInstruction( *ptr_tokens )) )
        {
            
            param_required = ParamRequired( instruction );
            
            ptr_tokens++;
        }
        
        i = 0;
        
        if( param_required == -1 )
        {
            
            ptr_tokens += instruction( ptr_tokens , NULL,NULL);
            
            param_required = 0;
            
            continue;
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
        
        if( instruction && operands[0] && operands[1] )
        {
 
            instruction( operands[0], operands[1] , operands [ 3 ]  );
        }
        
        
    }        
    
}