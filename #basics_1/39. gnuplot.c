#include <stdio.h>
#include <unistd.h>

int main()
{
    double t;

    FILE*p=popen("gnuplot -persist", "w");

    for(t=0; t<10; t+=0.1)
    {
        fprintf(p, "plot sin(x-%f)\n", t);
        fflush(p);
        usleep(100000);
    }

    pclose(p);


    return 0;
}
