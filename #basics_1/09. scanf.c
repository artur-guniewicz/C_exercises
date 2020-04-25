/* funkcja scanf */

#include <stdio.h>

int main()
{
    int a;
    char c, c2, c3;
    float x;
    double y;
    char s[20];

    printf("podaj liczbe calkowita: ");
    scanf("%i", &a);
    printf("a=%i\n", a);
    printf("podaj liczbe zmiennoprzecinkowa: ");
    scanf("%f", &x);
    printf("x=%f\npodaj y: ", x);
    scanf("%lf", &y);
    printf("y=%f\n", y);

    printf("podaj znak: ");
    scanf(" %c", &c);
    printf("c=%c c=%i\n", c, c);

    printf("podaj dwa znaki (oddzielone spacja): ");
    scanf(" %c %c", &c2, &c3);
    printf("c2=%c(%i), c3=%c(%i)\n", c2, c2, c3, c3);

    printf("podaj lancuch: ");
    scanf("%s", s);
    s[5]='\0';
    printf("podales: %s\n", s);

    for (a=0; s[a]!='\0'; a++)
        printf("s[%i]=%c\n", a, s[a]);

    while (a>=0)
        printf("%c", s[a--]);
    printf("\n");



    return 0;
}

/* scanf(" %c", &c); --> spacja przed %c znaczy - ignoruj znaki puste (enter, spacja) */

/* na końcu łańcucha znaków program wypisuje niewidzialny znak '\0', a więc można sprawdzić kiedy dany łacuch się kończy. Tak działa pętla for w tym przypadku: numeruje litery dopóki nie trafi na pusty znak, czyli na koniec łańcucha */
