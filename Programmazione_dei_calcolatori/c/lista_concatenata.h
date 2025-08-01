#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    float dato;
    struct nodo *succ, *prec;
}nodo;

typedef nodo *lista;

lista lista_vuota(){
    return NULL;
}
void lista_mostra(lista a){
    nodo *p;
    p=a;

    printf("\nStampo il contenuto della lista: ");
    
    while(p!=NULL){
        printf("%.2f ", p->dato);
        p=p->succ;
    }
    printf("\n\n");
}

nodo *lista_cerca(lista a, float v){
    nodo *p=a;
    while(p!=NULL && p->dato!=v){
        p=p->succ;
    }
    return p;

}

nodo *trova_nodo(lista a, int i){
    nodo *q=a;
    int j=0;
    while(q->succ!=NULL && j<i){
        q=q->succ;
        j++;
    }
    return q;
}
nodo *in_t(lista a, int k){
    nodo *p=malloc(sizeof(nodo));
    p->dato=k;
    p->succ=a;
    p->prec=NULL;
    if(a!=NULL)
        a->prec=p;
    return p;
}
nodo *in_1(lista a, int k){
    nodo *p=malloc(sizeof(nodo));
    p->dato=k;
    p->prec=a;
    if(a==NULL){
        p->succ=NULL;
        return p;
    }
    p->succ=a->succ;
    a->succ=p;
    return a;
}
nodo *in_c(lista a, int k){
    nodo *p=malloc(sizeof(nodo));
    p->dato=k;
    p->succ=NULL;
    if(a==NULL){
        p->prec=NULL;
        return p;
    }
    nodo *q=a;
    while(q->succ!=NULL){
        q=q->succ;
    }
    q->succ=p;
    p->prec=q;
    return a;
}

nodo *in_i(lista a, int k, int i){   
    if(i==0 || a==NULL || i<0){
        return in_t(a, k);
    }
    nodo *p=malloc(sizeof(nodo));
    p->dato=k; 
    nodo *q=trova_nodo(a, i-1);
    if(q->succ==NULL){
        p->prec=q;
        p->succ=NULL;
        q->succ=p;
    }
    else{
        p->prec=q;
        p->succ=q->succ;
        q->succ->prec=p;
        q->succ=p;
    }
    return a;
}
nodo *pop_t(lista a){
    if(a==NULL ||a->succ==NULL){
        free(a);
        return NULL;
    }
    nodo *q=a;
    a=a->succ;
    a->prec=NULL;
    free(q);
    return a;
}

nodo *pop_1(lista a){
    if(a==NULL ||a->succ==NULL){
        return a;
    }
    nodo *q=a;
    q=q->succ;
    a->succ=q->succ;
    q->succ=a;
    free(q);
    return a;
}

nodo *pop_c(lista a){
    if(a==NULL ||a->succ==NULL){
        free(a);
        return NULL;
    }
    nodo *q=a;
    while(q->succ!=NULL){
        q=q->succ;
    }
    nodo *h=q;
    q=q->prec;
    q->succ=NULL;
    free(h);
    return a;
}

nodo *pop_i(lista a, int i){
    if(a==NULL ||a->succ==NULL){
        free(a);
        return NULL;
    }
    if(i<=0){
        return pop_t(a);
    }
    nodo *q=trova_nodo(a, i-1);
    nodo *h=q;
    if(q->succ==NULL){
        q=q->prec;
        q->succ=NULL;
    }
    else{
        h=h->succ;
        q->succ->prec=q;
        q->succ=h->succ;
    }
    free(h);
    return a;
}