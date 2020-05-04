#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int a;
    struct list *next;
}
list;

list * add(list *l, int a)
{
    if (l==NULL)
    {
        l=(list*) malloc(sizeof(list));
        l->a=a;
        l->next=NULL;
    }
    else l->next=add(l->next, a);

    return l;
}

int main()
{
    list *l=NULL;

    if (l==NULL)
    {
        l=(list*) malloc(sizeof(list));
        l->a=1;
        l->next=NULL;
    }

    printf("%i\n", l->a);

    l->next=(list*) malloc(sizeof(list));

    l->next->a=2;
    l->next->next=NULL;
    printf("%i\n", l->next->a);

    putchar('\n');

    l=add(l, 1);
    printf("%i\n", l->a);

    l->next=add(l->next, 2);
    printf("%i\n", l->next->a);

    free(l->next);
    free(l);


    return 0;
}
