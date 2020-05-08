#include <stdio.h>

int main()
{
    int a;
    char s[20];
    double x;

    FILE*f=fopen("a.txt","rt");
    if(f==NULL)
    {
        printf("pliku nie udało się otworzyć\n");
        return 1;
    }

    fscanf(f, "%s", s);
    printf("s1=%s\n", s);
    fscanf(f, "%s", s);
    printf("s2=%s\n", s);
    fscanf(f, "%lf", &x);
    printf("x=%lf\n", x);
    fscanf(f, "%i", &a);
    printf("a1=%i\n", a);
    fscanf(f, "%i", &a);
    printf("a2=%i\n", a);




    return 0;
}
