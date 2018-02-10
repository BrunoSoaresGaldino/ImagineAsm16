#include <stdio.h>
#include <string.h>

#include <string.h>
#include <stdbool.h>

#include "../include/run.h"

#define MAX_FILE_SIZE 2048

extern short registers[ ];

#if defined (__linux) || defined (__APPLE__)

void ClearScreen( )
{
    fputs("\x1b[2J",stdout);
}

#else

#include <windows.h>


void ClearScreen( )
{
    HANDLE hConsole;
    COORD coord = {0, 0};
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD dwConsoleSize, dwWriten;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    dwConsoleSize = csbi.dwSize.X * csbi.dwSize.Y;
    FillConsoleOutputCharacter(hConsole, (TCHAR)' ', dwConsoleSize, coord, &dwWriten);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConsoleSize, coord, &dwWriten);
    SetConsoleCursorPosition(hConsole, coord);
 
}


#endif

void InteractiveMode( char *buffer )
{
    
    
    char input[1024] = "";
    
    char *ptr;
    char *aux;
    
    
    
    while( true )
    {
        ClearScreen( );
        
        puts("\n$$ para sair . - para apagar a ultima linha. -- para apagar todo o codigo");
        
        puts( buffer );
    
        fgets( input, 1024,stdin );
        
        if( strstr( input, "$$" ) )
        {
            break;
        }
        
        if( strstr( input ,"--" ) )
        {
         
            *buffer = '\0';
            
        }
        else if( strstr( input, "-" ) )
        {
            
            *ptr = '\0';
            
            ptr--;
            
            while( *ptr )
            {
                
                if( *ptr == '\n' )
                {
                    break;
                }
                
                ptr--;
            }
            
        }
        else
        {
            ptr = buffer + strlen( buffer );
            strcat( buffer , input );
        }
        
       
    }
    
    
    
    
}


int main( int argc ,char **argv )
{
    
    FILE *file;// ponteiro para o arquivo .asm
    
    size_t size;// usado para guardar o tamanho do arquivo
    
    char *data;// ponteiro para o buffer de dados
    
    char *tokens[MAX_TOKENS];// array para guardar os tokens do programa

    
    if( argc > 1 )
    {
        if( !( file = fopen( argv[1],"r") ) )
        {
            fprintf( stderr , "Erro ao abrir arquivo: %s",argv[1] );
            
            exit(EXIT_FAILURE);
            
        }
        
        size = FileSize( file );
        
        data = calloc( size , 1 );
    
        fread( data , 1 , size, file );
        
        fclose( file );
        
        file = NULL;
    }
    else
    {
        data = calloc( MAX_FILE_SIZE , 1 );
        
        InteractiveMode( data );
    }
    
    
    GetTokens( data , tokens );
    

    free( data );
    
    data = NULL;
    
    Run( tokens );
    
    printf("%hd",registers[0]);
    
    FreeTokens( tokens );
    
    return 0;
}
