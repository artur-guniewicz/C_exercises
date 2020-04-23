/* if-else --> podzielnosci */

#include <stdio.h>
#include <math.h>

int main()
{
    int a = 7;

    if (a%2==0) printf("%i jest liczba parzysta\n", a);

    if (a%2!=0) printf("%i jest liczba nieparzysta\n\n", a);

    if (a%2==0) printf("%i parzysta\n", a);
    else printf("%i nieparzysta\n\n", a);

    if (a%3==1) printf("reszta z dzielenia %i przez 3 wynosi 1\n", a);
    else if (a%3==2) printf("reszta z dzielenia %i prez 3 wynosi 2\n", a);
    else
    {
            printf("liczba %i jest podzielna przez 3\n\n", a);
            printf("tzn reszta z dzielenia %i przez 3 jest 0\n", a);
    }

    printf("po ifie\n");

    return 0;
}
