/* tablice */

#include <stdio.h>

int main()
{
    int a[20], b[]={1, 3, -2, 5, 7, 4, 8}, i;
    char s[]={'H', 'e', 'l', 98, 'o', '\0'}, s2[]={"Hello world"};

    printf("b[2]=%i, b[4]=%i\n", b[2], b[4]);

    for (i=0; i<20; i++) a[i]=i*i;
        printf("a[4]=%i\n", a[4]);

    printf("%s //// %s\n\n", s, s2);

    for (i=0; s2[i]!='\0'; ++i) s2[i]+=5;
        printf("s2=%s\n", s2);

    return 0;
}
