#include <stdio.h>
#include <math.h>

typedef double (*Function)(double, void*);

double Cos(double x, void *p)
{ return cos(x); }

double Pow(double x, void *p)
{ return pow(x, *(double*)p); }

double Q(double x, void *p)
{
    double *a=(double*)p;
    return a[0]+a[1]*x+a[2]*x*x;
}

void PrintTable(Function f, void *p)
{
    double x;
    for(x=0; x<=2; x+=0.2)
    { printf("%8.3f %10.6f\n", x, f(x,p)); }
    printf("\n");
}

int main()
{
    double a=3.1415, c[]={1,-2,2};

    PrintTable(Cos, NULL);
    PrintTable(Pow, &a);
    PrintTable(Q, c);


    return 0;
}
