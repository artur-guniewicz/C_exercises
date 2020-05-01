#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *w, *v;
    double *t;

    w=(int*) malloc(sizeof(int));
    *w=7;
    printf("*w=%i\n", *w);
    free(w);

    t=(double*) malloc(10*sizeof(double));
    if(t!=NULL)
    {
        t[5]=3.1415;
        printf("%f\n", t[5]);
        free(t);
    }
    else printf("problem z alokacją\n");


    return 0;
}
