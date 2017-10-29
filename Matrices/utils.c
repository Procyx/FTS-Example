#include "utils.h"
#include <errno.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int parse_int(char* str)
{
    char* buf;
    int val = (int) strtol(str, &buf, 10);
    
    if(val == 0)
        assert(errno != ERANGE);
    
    return val;
}

void println(char msg[])
{
    printf("%s\n", msg);
}

int nDigits(int n)
{
    return (n == 0 ? 1 : ((int)(log10(abs(n))+1) + (n < 0 ? 1 : 0)));
}
