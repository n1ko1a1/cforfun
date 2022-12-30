#include<stdlib.h>

/*gcc -pedantic-errors -Wall -Werror -g3 -fsanitize=undefined ub.c*/

int a = 0xecfb39f5;
unsigned short *d = (unsigned short *) &a;

int main()
{
    if((unsigned long) (65536 * d[1] + d[0]) < (1UL << 28))    
        abort ();
    return 0;
}