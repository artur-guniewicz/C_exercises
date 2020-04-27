#include <stdio.h>

void f5(char s[], int t[])
{
    printf("s=%s  t[0]=%i\n", s, t[0]);
    s[1]='z';
    t[0]*=111;
    printf("f5: s=%s  t[0]=%i\n", s, t[0]);
    printf("f5: sizeof(t)=%i\n", sizeof(t));
}

int main()
{
    int tab[]={6,7,8};
    char string[]="Hello World";

    f5(string,tab);

    putchar('\n');

    printf("main: string=%s  tab[0]=%i\n", string, tab[0]);
    printf("main: sizeof(tab)=%i\n", sizeof(tab));


    return 0;
}
