/* biblioteka <math.h> */

#include <stdio.h>
#include <math.h>

int main ()
{
    int i, j=5;
    float x, y;
    double z=3.1415;

    printf("%i %f %g\n", j, z, z);

    printf("%f %10.7f %15.10f\n", sin(z), sqrt(2.0), sqrt(3.0));

    return 0;
}

/* dodajemy -lm przy kompilacji gdy dolaczamy biblioteke <math.h> */
