
#include "../include/io.h"

size_t FileSize(FILE *file )
{
    size_t size = 0;
    
    fseek(file,0L,SEEK_END);
    size = ftell(file);
    fseek(file,0L,SEEK_SET);

    
    return size;
}

void GetTokens( char *buffer, char **tokens )
{
    
    int i;
    char *ptr;
    char delim[ ] = " \t\n,";
   
    ptr = strtok( buffer,delim ); 
    
    for ( i = 0 ; ptr && i < MAX_TOKENS ; ptr = strtok(NULL,delim), i++ )
    {
        *(tokens+i) = strdup(ptr);
    }
    
    *(tokens+i) = NULL;
    
}

void FreeTokens(char **tokens)
{
    
    while( *tokens )
    {
        free(*tokens++);
    }
}