#include <stdio.h>
#include <malloc.h>


struct nodo
{
    int valor;
    struct nodo *l;
    struct nodo *r;
};

struct nodo *raiz = NULL;
int flag;

void busca(struct nodo *,int);
struct nodo *novonodo(int);

void main()
{

    int busca_val;
    raiz = novonodo(50);
    raiz->l = novonodo(20);
    raiz->r = novonodo(30);
    raiz->l->l = novonodo(70);
    raiz->l->r = novonodo(80);
    raiz->l->l->l = novonodo(10);
    raiz->l->l->r = novonodo(40);
    raiz->l->r->r = novonodo(60);

    printf("\n \nValor a ser buscado:");
    scanf("%d", &busca_val);
    busca(raiz, busca_val);
    if (flag  ==  NULL)
    {
        printf("Elemento nao encontrado\n");
    }
}

struct nodo* novonodo(int valor)
{
    struct nodo *temp = (struct nodo *)malloc(sizeof(struct nodo));
    temp->valor = valor;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}



void busca(struct nodo *p, int val)
{
    if (!p)
    {
        return;
    }
    busca(p->l, val);
    if(p->valor == val)
    {
        printf("\nElemento presente.\n");
        flag = 1;
    }
    busca(p->r, val);
}

