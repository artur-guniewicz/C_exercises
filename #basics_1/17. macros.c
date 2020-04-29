/* MAKRA */

#include <stdio.h>

#define N 10
#define sqr(a) ((a)*(a))
#define wypisz(a) printf("%i\n", a);
#define wypisz2(a) printf(#a"=%i\n", a);
#define z(n) bbb##n
#define TEST printf("%s : %s : %i\n", __FILE__, __FUNCTION__, __LINE__); fflush(stdout);

int main()
{
   int x=5, bbb1=7, bbb2=8, bbb3=9;

    printf("%i\n", sqr(5+1));
    printf("%f\n", sqr(5.213));

    printf("%i\n", sqr(x++));
    printf("%i\n", x);

    putchar('\n');

    wypisz(x);

    putchar('\n');

    wypisz2(x);
    wypisz2(sqr(x++));

    putchar('\n');

    printf("%i %i\n", z(1), z(3));

    putchar('\n');

    TEST


    return 0;
}
