#include <stdio.h>

int main()
{
    int a;

    FILE*f=fopen("a.txt","wt");
    if(f==NULL)
    {
        printf("pliku nie udało się otworzyć\n");
        return 1;
    }

    fprintf(f, "Hello World\n");
    fprintf(f, "%f %i %i\n\n", 3.14, 2, 123); fflush(f); /* wymusza spłukanie strumienia */

    printf("Podaj a: ");
    scanf("%i", &a);


    fclose(f);



    return 0;
}
