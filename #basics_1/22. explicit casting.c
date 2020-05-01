#include <stdio.h>

int main()
{
    int a=6;
    double c=6.66;
    void *w;
    
    w=&a;
    
    /* jawne rzutowanie wskaźnika typu void na wskaźnik typu int */
    printf("%i\n", (*(int*)w)); 
    
    w=&c;
    (*(double*)w)=7.77;
    printf("%f %f\n", c, (*(double*)w));
  
    
    
    return 0;
}

  /* jawne rzutowanie wartości np. 
     1) (int) 3.14 = 3
     2) double x=3.1415;
        float f=(float) x; */
