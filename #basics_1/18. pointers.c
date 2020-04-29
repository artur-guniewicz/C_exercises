/* WSKAŹNIKI */

#include <stdio.h>

int main()
{
    int a=5, t[]={10,20,30,40,50};
    int *w, *v;

    w=&a;
    v=w;

    /* w tym momencie (*w)<=>a<=>(*v) */

    printf("%i %i %i\n", a, *w, *v);

    a++;
    printf("%i %i %i\n", a, *w, *v);

    *w=2;
    printf("%i %i %i\n", a, *w, *v);

    w=t; /* Nazwa tablicy to po prostu wskaźnik do zerowego elementu tablicy */

    /* w tym momencie w=&t[0] */

    printf("%i %i %i %i\n", *w, w[0], w[1], *(w+2));

    w++;
    printf("%i %i %i %i\n", *w, w[1], w[-1], 0[w]);
    /* skoro w[0]<=>*(w+0) to 0[w]<=>*(0+w)  */


    return 0;
}
