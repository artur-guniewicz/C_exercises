#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int a;
    struct list *next;
}
list;

int main()
{
    list a={1, NULL}, b={2, NULL}, c={3, NULL};

    a.next=&c;
    printf("%i %i %i %i\n", a.a, b.a, c.a, a.next->a); /* a.next->a = (*a.next).a */

    c.next=&b;
    printf("%i %i %i\n", a.a, a.next->a, a.next->next->a);



    return 0;
}
