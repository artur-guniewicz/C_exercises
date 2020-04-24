/* petla while */

#include <stdio.h>

int main()
{
    int i, j;

    i=0;
    j=0;

    while (++i<20)
    {
        printf("i=%i\n", i*=2*(j++));
    }
    printf("po petli i=%i\n", i);

    return 0;
}

/* 1) i=0+1=1 j=0 i=1*2*0=0
 * 2) i=0+1=1 j=0+1=1 i=1*2*1=2
 * 3) i=2+1=3 j=1+1=2 i=3*2*2=12
 * 4) i=12+1=13 j=2+1=3 i=13*2*3=78
 * 5) i=78+1=79
 */
