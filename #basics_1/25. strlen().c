#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

int main()
{
    char temp[50], *w[N];
    int n, l;

    for(n=0; n<N; ++n)
    {
        printf("podaj słowo: ");
        scanf("%s", temp);

        printf("twoje słowo: %s\njego długość: %i\n", temp, l=strlen(temp));

        w[n]=(char*)malloc(l+1);
        strcpy(w[n], temp);
    }

    putchar('\n');
    printf("Twoje słowa w odwrotnej kolejności niż je podałeś:\n");

    for(n=N-1; n>=0; --n)
    {
        printf("%s\n", w[n]);
        free(w[n]);
    }


    return 0;
}

/* strlen() podaje długość łańcucha wyłączając znak NULL ('/0') */
