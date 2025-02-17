#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    float dato;
    struct nodo *succ, *prec;
}nodo;

typedef nodo *clista;
void clista_mostra(clista);
nodo *clista_in0(clista, float);
nodo *clista_cerca(clista, float);
nodo *clista_out0(clista);
nodo *clista_out(clista, float);

clista clista_vuota();

int main(){
    clista L=clista_vuota();

    for(int i = 0; i < 10; i++){
        L = clista_in0(L, i);
    }

    clista_mostra(L);
    
    nodo *point = clista_cerca(L, 6.0);
    
    if (point != NULL)
        printf("%f\n", point->dato);
    else
        printf("Non trovato\n");

    L=clista_out0(L);
    clista_mostra(L);
    L=clista_out(L, 5);
    clista_mostra(L);

    return 0;
}
clista clista_vuota(){
    return NULL;
}

void clista_mostra(clista a){
    nodo *p;
    p=a;

    printf("Stampo il contenuto della lista: ");
    
    while(p!=NULL){
        if(p->succ==NULL){
            printf("%.2f ", p->dato);
            p=p->succ;
        }
        else{
            printf("%.2f, ", p->dato);
            p=p->succ;
        }
    }
    printf("\n");
}

nodo *clista_in0(clista a, float v){
    nodo *p=malloc(sizeof(nodo));
    p->dato=v;
    p->succ=a;
    p->prec=NULL;
    if(a!=NULL)
        a->prec=p;
    return p;
}

nodo *clista_cerca(clista a, float v){
    nodo *p=a;
    //while(p!=NULL && p->dato!=v){
    //    if(p->dato==v){
    //        return p;
    //    }
    //    p->succ=p
    //}
    //return NULL;
    while(p!=NULL && p->dato!=v){
        p=p->succ;
    }
    return p;
    //se il valore non viene trovato restituisce in automatico NULL dato che p punta a NULL
}

nodo *clista_out0(clista a){
    nodo *p=a;
    if(a==NULL){
        return NULL;
    }
    a=a->succ;
    if(a!=NULL){
        a->prec=NULL;
    }
    free(p);
    return a;
}

nodo *clista_out(clista a, float v){
    nodo *p=clista_cerca(a, v);
    if(p==NULL){
        return a;
    }
    nodo *k=p->prec;
    if(k==NULL){
        return clista_out0(p);
    }
    nodo *j=p->succ;
    if(p->succ==NULL){
        k->succ=NULL;
        free(p);
        return a;
    }
    k->succ=p->succ;
    j->prec=p->prec;
    free(p);
    return a;
}