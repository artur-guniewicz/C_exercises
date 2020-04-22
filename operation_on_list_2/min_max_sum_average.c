#include <stdio.h>

double max(double t[], int N)
{
    int i;
    double m=t[0];
    for(i=1; i<N; i++)
    {
        if(m<t[i]) m=t[i];
    }
    
    return m;
}

double min(double t[], int N)
{
    int i;
    double m=t[0];
    for(i=1; i<N; i++)
    {
        if(m>t[i]) m=t[i];
    }
    
    return m;
}

double suma(double t[], int N)
{
    int i;
    double S=0;
    for(i=0; i<N; i++)
    {
        S=S+t[i];
    }
    return S;
}

double srednia(double suma, int N)
{
    double srednia=0;
    
    srednia=(suma/N);
    
    return srednia;
}

int main()
{
    int i, M;
    double tab[50];
    
    tab[0]=0.2;
    
    for(i=0; i<50-1; i++)
    {
        tab[i+1]=3.8*tab[i]*(1-tab[i]);
    }
    for(i=0; i<50; i++)
    {
        printf("%g\n", tab[i]);
    }
    putchar('\n');
    
    M=sizeof(tab)/sizeof(tab[0]);
    
    printf("max: %g\n", max(tab, M));
    printf("min: %g\n", min(tab, M));
    printf("suma: %g\n", suma(tab, M));
    printf("srednia: %g\n", srednia(suma(tab, M), M));
    
    
    
    return 0;
}
