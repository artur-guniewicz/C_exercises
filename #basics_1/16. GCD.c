#include <stdio.h>

int gcd(int k, int n);

int counter=0;

int main()
{
    printf("gcd=%i\n", gcd(1024,3*64));
    printf("ilość wywołań funkcji - %i\n", counter);

    return 0;
}

int gcd(int k, int n)
{
    ++counter;
    if(k==0) return n;
    else return gcd(n%k,k);
}
