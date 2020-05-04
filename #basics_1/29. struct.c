#include <stdio.h>

struct S
{
    int a;
    char c;
    double d;
    char * s;
    float f;
}
a, B;

int main()
{
    struct S  x, t[10], *w, y={2, 'c', 3.1415, NULL, 2.1};
    a.c='z';

    printf("%i %f %c\n", y.a, y.d, y.c);

    w=&y;

    printf("%i %c %f\n", (*w).a, w->c, w->d);

    return 0;
}
