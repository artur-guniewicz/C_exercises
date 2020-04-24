/* inkrementacja */

#include <stdio.h>

int main()
{
    int a=3, b=6, c;

    printf("a=%i  b=%i\n", ++a, b++); /* ++a to to co a=a+1 */
    printf("a=%i  b=%i\n\n", a, b);

    c=(a++)*(--b);

    printf("a=%i  b=%i c=%i\n\n", a, b, c);

    a=6;

    printf("a=%i  a=%i  a=%i\n", a++, a++, a++);
    printf("a=%i  a=%i  a=%i\n", ++a, ++a, ++a);
    printf("a=%i\n\n", a);

    a=6;
    a++;
    printf("a=%i\n", a);

    a=6;
    ++a;
    printf("a=%i\n", a);

    a=6;
    a=a+1;
    printf("a=%i\n", a);

    a=6;
    a+=1;
    printf("a=%i\n", a);

    a=6;
    a*=2;
    printf("a=%i\n", a);

    a=6;
    a%=8;
    printf("a=%i\n", a);




    return 0;
}

/* a++ wypisanie a i następnie zwiększenie go o 1
 * ++a zwiększenie a o 1 i dopiero wypisanie go */

/* ++a;
 * a=a+1;
 * a+=1;
 * oznaczaja to samo */
