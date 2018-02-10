
#ifndef IO_H
#define IO_H


#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MAX_TOKENS 1000

size_t FileSize(FILE *);
void GetTokens(char *buffer,char **tokens);
void FreeTokens(char **tokens);



#endif