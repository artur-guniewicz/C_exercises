/* funkcje */

#include <stdio.h>

void f1()
{
    printf("f1:\n");
}

void f2(int x, int y, double z)
{
    printf("f2: a=%i  b=%i  c=%f\n", x, y, z);
}

int f3(int k, int l)
{
    return k*l;
}

void f4(int r, int s)
{
    printf("f4: a=%i  b=%i\n", r, s);
    r=7;
    s++;
    printf("f4: a=%i  b=%i\n", r, s);
}

int main()
{
    int a=5, b=8, c;

    f1();
    f1();

    putchar('\n');

    f2(6, 66, 3.1415);

    putchar('\n');

    c=f3(3, 23);
    printf("f3: c=%i  f3(70,6)=%i\n", c, f3(70,6));

    putchar('\n');

    f4(a,b);
    printf("main: a=%i  b=%i\n", a, b);
    f4(b,a);
    printf("main: a=%i  b=%i\n", a, b);



    return 0;
}

