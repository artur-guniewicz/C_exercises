/* specyfikatory formatowania */

#include <stdio.h>

int main ()

{
    /* %i-liczba całkowita, %c-znak(char), %x-system szesnastkowy, %o-system ósemkowy, %d-liczba całkowita */
    printf("c=%i, c=%c, c=%x, c=%o\n", 100, 100, 100, 100);
    printf("c=%i, c=%c, c=%x, c=%o\n", 'd', 'd', 'd'+1, 'd'-3);
    /* %f-liczby zmiennoprzecinkowe (6 cyfr po przecinku), %g-ostatnie zera nie są wpisywane, %e-wpisuje w formace naukowym */
    printf("x=%f, x=%g, x=%e\n", 666.14, 666.14, 666.14);
    /* %s-ciąg znaków */
    printf("%s, %s %s %s %s\n", "Hallo", "World", "ciąg", "znaków", "\n\n");

    /* 4%3 - reszta z dzielenia 4 przez 3 (=1) */
    printf("%d %f %d %i\n\n", 5*4, 4.0/5, 4%3, 7+2);

    /* jeżeli prawda to 1, jeżeli fałsz to 0 */
    printf("%d %i %d %d\n\n", 5<6, 5>6, 5==6, 5!=6);

    /* && - i, || - lub, ! - nie prawda, że*/
    printf("%d %d %d %d\n", 1&&1, 5&&6, 5&&0, 5||0);
    printf("%d %d\n\n", (5<6)&&(5%2==1), !5);

    /* operacje bitowe:
     a) 0101    b) 1001     c) 1001     d)  0001    e)  1000
        0110       1100        1100          <<3         >>2
        ----       ----        ----         ----        ----
        0100       1000        1101         1000        0010 */
    printf("%d %d %d %d %d\n\n", 5&6, 9&12, 9|12, 1<<3, 8>>2);

    return 0;
}
