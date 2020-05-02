#include <stdio.h>
#include <math.h>

void f1()
{ printf("f1:\n"); }

void f2()
{ printf("f2:\n"); }

void F(void (*g)())
{
    printf("F:\n");
    g();
}

/* typedef double real; real to teraz to samo co double */
typedef double (*Function)(double);
/* Function to teraz to samo co double (*nazwa_funkcji)(double) */

void PrintFunction(Function f[], int N)
{
    int n;
    for(n=0; n<N; ++n)
        printf("%10.6f", f[n](1));
    printf("\n");
}

int main()
{
    void (*f)(); /* nawias wokół wskaźnika odróżnia wskaźnik do funkcji od funkcji zwracającej wskaźnik */
    double (*g)(double);
    Function x;
    double (*h[])(double)={sin,cos,exp,tanh};
    Function p[]={sin,cos,exp,log,tan,tanh}; /* = double (*p[])(double)={rzeczy} */

    x=exp;
    printf("x(2)=%f\n", x(1));

    x=tan;
    printf("x(3)=%f\n", x(1));

    putchar('\n');

    g=sin;
    printf("g(1)=%f\n", g(1));

    g=cos;
    printf("g(1)=%f\n", g(1));

    putchar('\n');

    printf("h[2](1)=%f\n", h[2](1));

    putchar('\n');

    f=f1;
    f();
    f=f2;
    f();
    F(f1);
    F(f2);

    putchar('\n');

    PrintFunction(p,6);



    return 0;
}
