#include <stdio.h>

/* deklaracje funkcji */

int max(int t[], int N); 

unsigned int factorial(unsigned int);

int Fibb(int);

/* zmienna globalna */

int counter=0;

/* funkcja główna main */

int main()
{
    int tab[]={3,2,7,4,1,-1,6,0,3};
    
    printf("max=%i\n", max(tab, sizeof(tab)/sizeof(tab[0])));
    
    putchar('\n');
    
    printf("5!=%i\n", factorial(5));
    
    putchar('\n');
    
    printf("Fibb(20)=%i\n", Fibb(20));
    printf("ilość wywołań funkcji: %i\n", counter);
    
    return 0;
}

/* definicje funkcji */

int max(int t[], int N) 
{
    int m=t[0], n;
    
    for(n=1;n<N;++n)
        if(t[n]>m) m=t[n];
    
    return m;
}

unsigned int factorial(unsigned int n)
{
    unsigned int res;
    printf("liczę %i!\n", n);
    
    if(n==0) res=1;
    else res=n*factorial(n-1);
    printf("policzyłem %i!=%i\n", n, res);
    return res;
}

int Fibb(int n)
{
    ++counter;
    if(n==1||n==2) return 1;
    else return Fibb(n-1)+Fibb(n-2);
}
