/* wskaźniki w funkcjach */

#include <stdio.h>

void f(int a)
{
    a=5;
}

void g(int *a)
{
    *a=5;
}

int * h(int *t)
{
    t+=2;
    (*t)+=4;
    return t;
}

int main()
{
    int i=3, j=7, t[]={10,20,30,40,50}, *w;
    f(i);
    g(&j);
    printf("%i %i\n", i, j);

    w=h(t+2);
    printf("%i\n", *w);



    return 0;
}
