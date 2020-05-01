#include <stdio.h>

/* const gwarantuje że nie zmieni się wartość danego adresu */
int max(const int *a,int N)
{
    int m=*a, n;
    for(n=1; n<N; ++n)
        if(*(a+n)>m) m=*(a+n);

    /* *a=12; - komilator wyrzuci error (bo próbujemy zmienić coś co jest const) */

    return m;
}


/* * łączy się z int więc funkcja ma zwracać wskaźnik do zmiennej typu int */
int * max2(const int *a, int N)
{
    int *w=a, n;
    for(n=1; n<N; ++n)
        if(*w<*(a+n)) w=a+n;

    return w;
}

void invcpy(int *c, const int *a, int N)
{
    int n;
    for(n=0; n<N; n++)
        *(c+n)=*(a+N-1-n);
}

int main()
{
    int t[]={1,2,8,3,5,4}, c[6], b, *w;
    const int z=63;

    printf("max=%i\n", max(t,6));

    /* z=73; - kompilator wyrzuci error (bo próbujemy zmienić coś co jest const) */

    /* sposób na obejście tego errora: */
    printf("z=%i\n", z);
    w=&z;
    *w=73;
    printf("z=%i\n", z);

    putchar('\n');

    w=max2(t,6);
    printf("max2=%i\n", *w);
    printf("na pozycji %li\n", w-t);

    putchar('\n');

    invcpy(c, t, 6);
    for (b=0; b<6; b++)
        printf("c[%i]=%i\n", b, c[b]);




    return 0;
}
