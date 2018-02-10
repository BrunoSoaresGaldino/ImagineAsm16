#ifndef ERROR_H
#define ERROR_H

#include <stdio.h>
#include <stdlib.h>

enum Error{ OPERAND_MISSING ,INVALID_INSTRUNCTION ,NULL_OPERAND ,DIVISION_BY_ZERO , INVALID_LEFT_OPERAND , INVALID_OPERATION };

void AbortOnError( int );


#endif