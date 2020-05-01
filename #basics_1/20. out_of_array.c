/* ułożenie zmiennych w pamięci komutera. Wychodząc zmienną z jednej tablicy można przez przypadek wejść do innej tablicy. */

#include <stdio.h>

int main()
{
    int a, b, s[5], t[10];

    printf("%li\n", &b-&a);
    printf("%li %li %li\n", s-&b, t-s, &a-t);
    t[13]=7;
    printf("%i %i\n", t[13], s[4]);


    return 0;
}
