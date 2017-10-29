#ifndef utils_h
#define utils_h

#include <stdio.h>

typedef enum { false, true } bool;

int parse_int(char* str);

void println(char msg[]);

int nDigits(int n);

#endif 
