#include <stdio.h>

struct A
{
    int a;
    float x;
} p1={3, 3.1415}, p2;

int main()
{
    FILE*f=fopen("b.txt", "wb");

    int a=6, b, l;
    double x=7.2, y, t[]={7, 8.1, 3.2}, s[3];

    fwrite(&a, sizeof(a), 1, f);
    fwrite(&x, sizeof(x), 1, f);
    fwrite(t, sizeof(double), 3, f);
    fwrite(&p1, sizeof(p1), 1, f);

    fclose(f);

    f=fopen("b.txt", "rb");
    fread(&b, sizeof(b), 1, f);
    fread(&y, sizeof(y), 1, f);
    fread(s, sizeof(double), 3, f);
    fread(&p2, sizeof(p2), 1, f);

    printf("%f\n", p2.x);

    l=ftell(f); /*ftell mówi nam w którym miejscu pliku się znajdujemy */
    printf("%i\n", l);

    fclose(f);



    return 0;
}
