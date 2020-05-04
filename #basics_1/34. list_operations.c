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

void printList1(list *l)
{
    if(l!=NULL)
    {
        printf("%i ", l->a);
        printList1(l->next);
    }
}

void printList2(list *l)
{
    if(l!=NULL)
    {
        printList2(l->next);
        printf("%i ", l->a);
    }
}

void freeList(list *l)
{
    if(l!=NULL)
    {
        freeList(l->next);
        free(l);
    }
}

int main()
{
    list *l=NULL;

    int n;

    for(n=0;n<10;++n) l=add(l,n);

    printList1(l);
    putchar('\n');

    printList2(l);
    putchar('\n');

    freeList(l);


    return 0;
}
