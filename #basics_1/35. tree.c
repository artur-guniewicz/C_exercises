#include <stdio.h>
#include <stdlib.h>

typedef struct Tree
{
    int a, counter;
    struct Tree *left, *right;
}
Tree;

Tree * add(Tree *t, int a)
{
    if(t==NULL)
    {
        t=(Tree*)malloc(sizeof(Tree));
        t->left=t->right=NULL;
        t->a=a;
        t->counter=1;
    }
    else if(a>t->a) t->right=add(t->right, a);
    else if(a<t->a) t->left=add(t->left, a);
    else t->counter++;

    return t;
}

void printTree1(Tree *s)
{
    if(s!=NULL)
    {
        printTree1(s->left);
        printf("%i %i\n", s->a, s->counter);
        printTree1(s->right);
    }
}

void printTree2(Tree *s)
{
    if(s!=NULL)
    {
        printTree2(s->right);
        printf("%i %i\n", s->a, s->counter);
        printTree2(s->left);
    }
}

void printTree3(Tree *s)
{
    if(s!=NULL)
    {
        printf("(");
        printTree3(s->left);
        printf("%i", s->a);
        printTree3(s->right);
        printf(")");
    }
}

Tree * rotateLeft(Tree *t)
{
    if(t!=NULL)
    {
        Tree *t2=t->right;
        if(t2!=NULL)
        {
            Tree *B=t2->left;
            t2->left=t;
            t->right=B;
            return t2;
        }
    }
    return t;
}

Tree * rotateRight(Tree *t)
{
    if(t!=NULL)
    {
        Tree *t2=t->left;
        if(t2!=NULL)
        {
            Tree *B=t2->right;
            t2->right=t;
            t->left=B;
            return t2;
        }
    }
    return t;
}

void freeTree(Tree *t)
{
    if(t!=NULL)
    {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

int main()
{
    Tree *t=NULL;

    t=add(t, 8);
    t=add(t, 15);
    t=add(t, 17);
    t=add(t, 13);
    t=add(t, 7);
    t=add(t, 13);


   /* Wczytujemy tyle liczb ile chcemy, az do nacisniecia ctrl-D
    while(scanf("%i", &p)!=EOF)
    { t = add(t, p); } */

    printf("%i %i\n", t->right->left->a, t->right->left->counter);
    printf("**********\n");

    printTree1(t);
    printf("**********\n");
    printTree1(t->right);
    printf("**********\n");

    printTree2(t);
    printf("**********\n");
    printTree2(t->right);
    printf("**********\n");

    printTree3(t);
    putchar('\n');
    printTree3(t->left);
    putchar('\n');
    printTree3(t->right);
    putchar('\n');
    printf("**********\n");

    t=rotateLeft(t);
    printTree3(t);
    putchar('\n');
    printTree3(t->left);
    putchar('\n');
    printTree3(t->right);
    putchar('\n');
    printf("**********\n");

    t=rotateRight(t);
    printTree3(t);
    putchar('\n');
    printTree3(t->left);
    putchar('\n');
    printTree3(t->right);
    putchar('\n');
    printf("**********\n");

    freeTree(t);


    return 0;
}
