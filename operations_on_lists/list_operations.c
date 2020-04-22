/*
Artur Guniewicz
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    struct list *next;
}
list;

list * add(list *l, int x)
{
    if(l==NULL)
    {
        l=(list*)malloc(sizeof(list));
        l->value=x;
        l->next=NULL;
    }
    else l->next=add(l->next, x);

    return l;
}

list * create(list *l, int N)
{
    int a, n;
    for(n=0; n<N; n++)
    {
        scanf("%i", &a);
        l=add(l, a);
    }
    return l;
}

void printList(list *l)
{
    if(l==NULL) printf("Twoja lista jest pusta");
    while(l!=NULL)
    {
        printf("%i ", l->value);
        l=l->next;
    }
}

int list_lenght(list *l)
{
    list *L;
    int n=0;

    L=l;
    while(L!=NULL)
    {
        n++;
        L=L->next;
    }
    return n;
}

list * delete(list *l, int x)
{
    list *L;
    do
    {
        L=l;
        if(L==NULL) return l;
        else if(L->value==x)
        {
            l=L->next;
            L=l;
        }
    }
    while(L->value==x);

    while(L->next!=NULL)
    {
        if(L->next->value==x)
        {
            L->next=L->next->next;
        }
        else L=L->next;
    }
    return l;
}

list * add_before(list *l, int e, int element)
{
    list *L=NULL, *N=l, *act, *a;
    L=add(L, element);

    if(N==NULL || (N->next==NULL && N->value!=e))
    {
        printf("\nLista pierwotna nie zawiera elementu %i\n", e);
        return l;
    }

    if(N->value==e)
    {
        L->next=N;
        return L;
    }
    else
    {
        act=N->next;
        a=N;

        do
        {
            if(act->value==e)
            {
                a->next=L;
                L->next=act;
                return l;
            }
            else
            {
                a=a->next;
                act=act->next;
            }
        }
        while(act!=NULL);
    }

    printf("\nLista pierwotna nie zawiera elementu %i\n", e);
    return l;
}

list * delete_duplicates(list *l)
{
    list *act=l, *L, *a;
    if(act==NULL || act->next==NULL) return l;

    do
    {
        L=act->next;
        a=act;

        while(L!=NULL)
        {
            if(act->value==L->value)
            {
                a->next=a->next->next;
                L=L->next;
            }
            else
            {
                L=L->next;
                a=a->next;
            }
        }
        act=act->next;
        if(act==NULL) break;
    }
    while(act->next!=NULL);

    return l;
}

list * reverse(list *l)
{
    list *act=l, *a, *b;
    if(act==NULL || act->next==NULL)
    {
        return act;
    }

    a=act->next;
    act->next=NULL;
    b=act;
    act=a;

    while(a->next!=NULL)
    {
        a=act->next;
        act->next=b;
        b=act;
        act=a;
    }
    act->next=b;

    return act;
}


void sort(list *l)
{
    int swapped, temp;
    list *L;

    do
    {
        swapped=0;
        L=l;

        while(L->next!=NULL)
        {
            if(L->value > L->next->value)
            {
                temp=L->value;
                L->value=L->next->value;
                L->next->value=temp;
                swapped = 1;
            }
            L = L->next;
        }
    }
    while(swapped);
}

list * merge(list *L, list *M)
{
    list *Head, *N;

    if(L==NULL) return M;
    if(M==NULL) return L;

    if(L->value<M->value)
    {
        Head=L;
        L=L->next;
    }
    else
    {
        Head=M;
        M=M->next;
    }

    N=Head;

    while(L!=NULL && M!=NULL)
    {
        if(L->value<M->value)
        {
            N->next=L;
            L=L->next;
        }
        else
        {
            N->next=M;
            M=M->next;
        }
        N=N->next;
    }

    if(L==NULL) N->next=M;
    if(M==NULL) N->next=L;

    return Head;
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
    list *l=NULL, *m=NULL;
    int N, M, choice, end=1, x, e;

    puts("Program pokazuje różne operacje na liście jednokierunkowej!\n");
    puts("Stwórz na początek swoją listę!");
    printf("--> Jakiej Twoja lista ma być długości? ");
    scanf("%i", &N);
    if(N==0) printf("\nUWAGA! Stworzyłeś pustą listę!\n");
    else printf("--> Uzupełnij swoją listę podając %i liczb (klikając ENTER po każdej liczbie):\n", N);
    l=create(l, N);

    do
    {
        puts("\nCo chcesz zrobić?");
        printf("[0] Stworzyć swoją listę od nowa\n");
        printf("[1] Wypisać swoją listę\n");
        printf("[2] Sprawdzić długość swojej listy\n");
        printf("[3] Usunąć elementy o wskazanej warości z listy\n");
        printf("[4] Dodać element przed element w liście\n");
        printf("[5] Usunąć z listy duplikaty\n");
        printf("[6] Odwrócić swoją listę\n");
        printf("[7] Posortować swoją listę\n");
        printf("[8] Stworzyć nową listę, scalić ze swoją i wypisać posortowaną\n");
        printf("[9] Zakończyć program\n");
        printf("--> Twój wybór: ");
        scanf("%i", &choice);

        switch(choice)
        {
            case 0 :
                        l=NULL;
                        printf("\n--> Podaj długość nowej listy: ");
                        scanf("%i", &N);
                        if(N==0) printf("Stworzyłeś pustą listę!\n");
                        else printf("--> Uzupełnij swoją listę podając %i liczb:\n", N);
                        l=create(l, N);
                        break;

            case 1 :
                        putchar('\n');
                        printList(l);
                        putchar('\n');
                        break;

            case 2 :
                        printf("\n--> Twoja lista ma %i elementów\n", list_lenght(l));
                        break;

            case 3 :
                        printf("\n--> Jakie elementy chcesz usunąć? ");
                        scanf("%i", &x);
                        l=delete(l, x);
                        printList(l);
                        putchar('\n');
                        break;

            case 4 :
                        printf("\n--> Jaki element chcesz wstawić? ");
                        scanf("%i", &x);
                        printf("--> Przed jaki element chcesz wstawić? ");
                        scanf("%i", &e);
                        l=add_before(l, e, x);
                        printList(l);
                        putchar('\n');
                        break;

            case 5 :
                        putchar('\n');
                        l=delete_duplicates(l);
                        printList(l);
                        putchar('\n');
                        break;

            case 6 :
                        putchar('\n');
                        l=reverse(l);
                        printList(l);
                        putchar('\n');
                        break;

            case 7 :
                        putchar('\n');
                        sort(l);
                        printList(l);
                        putchar('\n');
                        break;

            case 8 :
                        printf("\n--> Jakiej długości ma być druga lista? ");
                        scanf("%i", &M);
                        if(M==0)
                        {
                            sort(l);
                            printf("\nUWAGA! Druga lista jest pusta - zostanie wypisana lista pierwotna\n");
                            printList(l);
                            putchar('\n');
                        }
                        else
                        {
                            printf("--> Uzupełnij drugą listę podając %i liczb:\n", M);
                            m=create(m, M);
                            sort(l);
                            sort(m);
                            putchar('\n');
                            l=merge(l, m);
                            printList(l);
                            putchar('\n');
                            m=NULL;
                        }

                        break;

            case 9 :
                        end=0;
                        break;

            default :
                        printf("\n--> Podaj cyfrę z zakresu [0,9]!\n");
                        break;
        }
    }
    while(end);

    freeList(l);
    freeList(m);

    printf("\nMiłego dnia!\n");

    return 0;
}
