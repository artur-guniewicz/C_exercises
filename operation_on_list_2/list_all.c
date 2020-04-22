#include <stdio.h>
#include <stdlib.h>

double S=0;
double sr=0;

typedef struct list
{
    double value;
    struct list *next;
}
list;

list * add(list *l, double x)
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

void printList(list *l)
{
    if(l==NULL) printf("Twoja lista jest pusta\n");
    while(l!=NULL)
    {
        printf("%g\n", l->value);
        l=l->next;
    }
}

double max(list *l)
{
    double max=l->value;
    while(l->next!=NULL)
    {
        if(max < l->next->value)
        {
            max=l->next->value;
        }
        
        l=l->next;
    }
  
    return max;
}

double min(list *l)
{
    double min=l->value;
    while(l->next!=NULL)
    {
        if(min > l->next->value)
        {
            min=l->next->value;
        }
        
        l=l->next;
    }
 
    return min;
}

double suma(list *l)
{
    if(l!=NULL)
    {
        S=S+l->value;
        suma(l->next);
    }
    
    return S;
}

double srednia(list *l)
{  
    if(l!=NULL)
    {
        sr=sr+l->value;
        srednia(l->next);
    }
    
    return sr/50.0;
}

list * ostatni_element(list *l)
{
    while(l!=NULL && l->next!=NULL)
    {
        l=l->next;
    }
    return l;
}

list * podzial(list *l, list *ost_el, list **poczatek, list **koniec)
{
    list *m=ost_el, *k=NULL, *obecny=l, *end=m;
    
    while(obecny!=m)
    {
        if(obecny->value < m->value)
        {
            if((*poczatek)==NULL) (*poczatek)=obecny;
            
            k=obecny;
            obecny=obecny->next;
        }
    
        else
        {
            list *temp=obecny->next;
            
            if(k) k->next=obecny->next;
    
            obecny->next=NULL;
            end->next=obecny;
            end=obecny;
            obecny=temp;
        }
        
    } 
    
    if((*poczatek)==NULL) (*poczatek)=m;
  
    (*koniec)=end;
  
    return m;
}

list * sort(list *l,  list *ost_el)
{
    list *poczatek=NULL, *koniec=NULL, *m;
    
    if(l==NULL||l==ost_el) return l;
        
    m=podzial(l, ost_el, &poczatek, &koniec);
        
    if(poczatek!=m)
    {
        list *temp=poczatek;
        
        while(temp->next!=m) temp=temp->next;
            
        temp->next=NULL;
        poczatek=sort(poczatek,temp);
        temp=ostatni_element(poczatek);
        temp->next=m;
    }
    
    m->next=sort(m->next, koniec);
    
    return poczatek;
}

void sortowanie(list *l)
{
    l=sort(l, ostatni_element(l));
    return;
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
    list *l=NULL, *m;
    int i;
    double x;
    
    l=add(l, 0.2);
    m=l;
    
    for(i=0; i<50-1; ++i) 
    {
        x=l->value;
        l=add(l, 3.8*x*(1-x));
        l=l->next;
    }
    
    printf("max: %g\n", max(m));
    printf("min: %g\n", min(m));
    printf("suma: %g\n", suma(m));
    printf("średnia: %g\n", srednia(m));
    putchar('\n');
    
    puts("lista przed posortowaniem:");
    printList(m);
    putchar('\n');    
  
    sortowanie(m);
    
    puts("lista po posortowaniu:");
    printList(m);
    
    freeList(m);
  
  
    return 0;
}
