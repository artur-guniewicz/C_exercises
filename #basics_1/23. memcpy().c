/* funkcja memcpy(dest, source, n) - kopije z source n bajtów do dest */

#include <stdio.h>
#include <string.h>

int main()
{
    int t[5]={3,2,1,4,0}, s[5];
    double v[]={4.1,7.2,3.5}, q[3];

    memcpy(s, t, sizeof(t));
    memcpy(q, v, sizeof(v));

    printf("s[1]=%i t[1]=%i\n", s[1], t[1]);
    printf("q[1]=%f v[1]=%f\n", q[1], v[1]);


    return 0;
}

/* memcpy(void * dst, void * src, int n) n wskazuje ile bitów ma być skopiowanych z src do dst */
