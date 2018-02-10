#include "../include/error.h"

static char *error_list[ ] = { "OPERAND_MISSING","INVALID_INSTRUNCTION","NULL_OPERAND","DIVISION_BY_ZERO" , "INVALID_LEFT_OPERAND" , "INVALID_OPERATION"};

void AbortOnError( int error_code )
{
    
    puts( error_list[ error_code ] );
    
    exit( EXIT_FAILURE );
    
}