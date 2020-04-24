/* Program wypisze dzielniki liczby j */

#include <stdio.h>

int main()
{
    int i=0, j=60*24;

    while (i++<j)
    {
        if(j%i==0)
        {
            printf("  %i  \n", i);
        }
    }



    return 0;
}


/*
#include <stdio.h>

int main()
{
    int a=0, b, counter=0;
    printf("Podaj liczbę której dzielniki chcesz sprawdzić: ");
    scanf("%i", &b);

    while(a++<b)
    {
        if(b%a==0)
        {
            counter++;
            printf("%i. %i\n", counter, a);
        }
    }


    return 0;
}
*/
