#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ditem {
        char *k;  // chiave
        int v; // valore
} ditem;  // item del dizionario, coppia chiave-valore

typedef struct nodo {
    ditem dato;
    struct nodo *succ, *prec;
} nodo;

typedef nodo *clista; // lista concatenata

typedef struct dict {
    clista *a;
    int m;
} dict;  // dizionario con m liste di trabocco

int h(char*,dict);

/* dizionario*/
dict dict_init();
int dict_cerca(dict, char*);
dict dict_add_item(dict, char*, int);
void dict_mostra(dict);
int dict_get(dict, char*);
dict dict_del(dict, char*);


/* lista concatenata */
clista clista_vuota();
nodo *clista_cerca(clista, char*);
nodo *clista_in0(clista, ditem);
void clista_mostra(clista);
nodo *clista_out(clista, char*);
nodo *clista_out0(clista);


int main(){
    dict d = dict_init();
    
    char *dataset[] = {"davide", "dannis", "elisa", "vanessa", "francesca", "sergio", "jacopo", "massimo", "ludovico", "anastasia", "edoardo", "pierre", "valerio", "ginevra", "domenico", "whendy", "mateo", "tommaso", "simone", "mario", "antonio"};
    
    int n = sizeof(dataset)/sizeof(char*);
    
    for(int i = 0; i < n; i++){
        d = dict_add_item(d, dataset[i], i);
    }
    dict_mostra(d);
    d = dict_add_item(d, dataset[1], 80);
    dict_mostra(d);
    int v= dict_get(d, "dannis");
    if(v!=-1){
        printf("%d", v);
    }
    else{
        printf("Elemento non trovato");
    }
    
    
}

int hsomma(char *k){
    int h = 0;
    while ( *k != '\0' ){
        h += *k;
        k++;
    }
    return h;
}

int h(char *k, dict d){
    return hsomma(k) % d.m;
}

dict dict_del(dict d, char *k) {
    int i = h(k, d);
    
    d.a[i] = clista_out(d.a[i], k);
        
    return d;
}

int dict_get(dict d, char *k){
    //restituisce -1 see l'elemento non si trova nel dizionario
    if(dict_cerca(d, k) == 0){
        return -1;
    }
    
    int i = h(k, d);
    nodo *p = clista_cerca(d.a[i], k);
    
    return p->dato.v;
}

int dict_cerca(dict d, char *k){
    int i = h(k, d);
    nodo *p = clista_cerca(d.a[i], k);
    
    if (p == NULL)
        return 0;
    else
        return 1;
}

void dict_mostra(dict d){
    int i;
    
    for(i = 0; i < d.m; i++){
        printf("d[%d] = ", i);
        clista_mostra(d.a[i]);
    }
}

dict dict_add_item(dict d, char *k, int v){
    int i = h(k, d);
    nodo *p = clista_cerca(d.a[i], k);
    
    if( p!=NULL ){ // k e' una chiave del dizionario, aggiorno il valore 
        p->dato.v = v;
    } else {
        ditem itm = {NULL, v};
        itm.k = malloc(sizeof(char)*(strlen(k)+1));
        strcpy(itm.k, k);
        d.a[i] = clista_in0(d.a[i], itm);
    }
    
    return d;
}

dict dict_init(){
    dict d = {NULL, 7};
    
    d.a = malloc(d.m*sizeof(clista));
    
    for(int i=0; i < d.m; i++)
        d.a[i] = clista_vuota();
    
    return d;
}

clista clista_out0(clista a){
    clista p = a;
    if( a == NULL)
        return NULL;
    a = a->succ;
    if (a != NULL)
        a->prec = NULL;
    free(p->dato.k);
    free(p);
    return a;
}

clista clista_out(clista a, char *k){
    nodo *p = clista_cerca(a, k);
    if (p == NULL)
        return a;
    
    nodo *q = p->prec;
    
    if ( q == NULL){ // p e' il primo nodo della lista ovvero p == a
        return clista_out0(p);
    }
    
    q->succ = clista_out0(q->succ);
    if (q->succ != NULL)
        q->succ->prec = q;
    
    return a;
}

void clista_mostra(clista a){
    nodo *p;
    
    p = a;
    
    while( p != NULL ){ 
        printf("(%s, %d), ", p->dato.k, p->dato.v  ); 
        p = p->succ; 
    }
    
    printf("\n");
}

nodo *clista_in0(clista a, ditem v){
    nodo *p = malloc(sizeof(nodo));
    p->dato = v;
    p->succ = a;
    p->prec = NULL;
    if (a != NULL)
        a->prec = p;
    a = p;
    return a;
}

nodo *clista_cerca(clista a, char *k){
    nodo *p = a;
    
    while( p != NULL && strcmp(p->dato.k, k)!=0 ){
        p = p->succ;
    }
    
    return p;
}

clista clista_vuota(){
    return NULL;
}

