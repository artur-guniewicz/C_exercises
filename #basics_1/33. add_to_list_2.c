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

    l=add(l, 1);
    l=add(l, 5);
    l=add(l, 7);
    printf("%i\n", l->a);
    printf("%i\n", l->next->a);
    printf("%i\n", l->next->next->a);

    free(l->next);
    free(l);


    return 0;
}
