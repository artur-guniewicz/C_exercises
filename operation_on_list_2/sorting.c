#include <stdio.h>

void zamiana(double *x, double *y)
{
    double t=*x;
    *x=*y;
    *y=t;
}

int podzial(double t[], int poczatek, int koniec)
{
    double x=t[koniec];
    int i=poczatek-1, j;
    
    for(j=poczatek; j<=koniec-1; j++)
    {
        if(t[j]<=x)
        {
            i++;
            zamiana(&t[i], &t[j]);
        }
    }
    zamiana(&t[i+1], &t[koniec]);
    return i+1;
}


void sortowanie(double t[], int poczatek, int koniec)
{
    double x;
    
    if(poczatek<koniec)
    {
        x=podzial(t, poczatek, koniec); /* wywołanie rekurencyjne */
        sortowanie(t, poczatek, x-1);
        sortowanie(t, x+1, koniec);
    }
}

int main()
{
    int i, M;
    double tab[50];
    
    M=sizeof(tab)/sizeof(tab[0]);
    
    tab[0]=0.2;
    
    for(i=0; i<50-1; i++)
    {
        tab[i+1]=3.8*tab[i]*(1-tab[i]);
    }
    
    puts("tablica przed posortowaniem:");
    
    for(i=0; i<50; i++)
    {
        printf("%g\n", tab[i]);
    }
    putchar('\n');
    
    sortowanie(tab, 0, M-1);
    
    puts("tablica po posortowaniu:");
    for(i=0; i<50; i++)
    {
        printf("%g\n", tab[i]);
    }
    
    return 0;
}
