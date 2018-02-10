
#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H


#include <stdlib.h>
#include <string.h>

#include "error.h"
#include "registers.h"
#include "run.h"

typedef struct
{
    char *name;
    void *func;
    
} InstructionMap;


void MOV( short *, short * );
void ADD( short *, short * );
void SUB( short *, short * );
void MUL( short *, short * );
void DIV( short *, short * );
void NEG( short * );
void INC( short * );
void DEC( short * );
int  REP( char **tokens );

void *GetInstruction( const char *);

int ParamRequired( void *func );

#endif