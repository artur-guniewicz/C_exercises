#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=5;
    double c=3.1415, *t;
    void *w;

    w=&a;

    printf("%i\n", *(int*)w);

    w=&c;

    printf("%f\n", *(double*)w);

    t=(double*)malloc(sizeof(double)*100);
    /* void * malloc(size_t) zwraca wartość typu void więc musimy ją zrzutować na typ double */
    t[0]=t[99]=66;
    printf("%f\n", *t);
    free(t);


    return 0;
}


