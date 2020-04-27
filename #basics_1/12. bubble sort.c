/* program sortuje tablicę (sortowanie bąbelkowe) */

#include <stdio.h>

int main()
{
    int t[]={5,3,2,9,7,1,8,4,6}, N, n, j, k, temp, counter;

    printf("%li %li %li\n", sizeof(n), sizeof(int), sizeof(t));
    N=sizeof(t)/sizeof(t[0]);
    printf("N=%i\n", N);

    putchar('\n');

    for(n=0;n<N;n++) printf("%i ", t[n]);

    putchar('\n');


    for(j=0; j<N-1; ++j)
    {
        counter=0;
        for(k=0; k<N-1-j; ++k)
        {
            if(t[k]>t[k+1])
            {
                temp=t[k];
                t[k]=t[k+1];
                t[k+1]=temp;
                ++counter;
            }
        }
        if(counter==0) break;
    }

    for(n=0;n<N;n++) printf("%i ", t[n]);
    putchar('\n');

    return 0;
}

/* sortowanie przez wstawianie

#include <stdio.h>

int main()
{
    int t[]={2,6,4,5,9,1,3,0,8,7}, N, x, i, j, klucz;
    N=sizeof(t)/sizeof(t[0]);
    printf("rozmiar tablicy: %i\n\n", N);

    printf("tablica przed posortowaniem: \n");
    for(x=0; x<N; x++) printf("%i ", t[x]);
    putchar('\n');

    for(i=1; i<N; i++)
    {
        klucz=t[i];
        j=i-1;
        while(j>=0 && t[j]>klucz)
        {
            t[j+1]=t[j];
            j--;
            t[j+1]=klucz;
        }
    }

    printf("tablica po posortowaniu: \n");
    for(x=0; x<N; x++) printf("%i ", t[x]);
    putchar('\n');

    return 0;
}
*/
