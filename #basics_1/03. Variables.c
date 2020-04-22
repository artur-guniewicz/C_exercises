#include <stdio.h>

int main()

{
    int a, b, c=5;
    unsigned char s='c', w=100, v;
    a=17;
    b=a+c;

    printf("a=%d b=%d c=%d\n\n", a, b, c);

    a=1;
    printf("a=%d\n", a);

    a=(1/2);
    printf("a=%d\n", a);

    printf("s=%d s=%c w=%c s+w=%d\n", s, s, w, s+w);

    v=s+w+100;
    printf("v=%i\n", v);

    return 0;
}
