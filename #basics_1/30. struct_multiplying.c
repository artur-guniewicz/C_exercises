#include <stdio.h>

typedef struct frac
{ int a, b; } frac;

frac mul(frac A, frac B)
{
    frac C;
    C.a=A.a*B.a;
    C.b=A.b*B.b;
    return C;
}

int main()
{
    frac a={1,2}, b={3,4}, c;

    c=mul(a,b);
    printf("%i / %i\n", c.a, c.b);

    a=mul(b,c);
    printf("%i / %i\n", a.a, a.b);


    return 0;
}
