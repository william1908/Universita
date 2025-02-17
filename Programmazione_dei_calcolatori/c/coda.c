#include<stdio.h>
#include<stdlib.h>

typedef struct nodo {
	float dato;
	struct nodo *succ;
}nodo;

typedef struct coda {
	nodo *h;  // head, il puntatore al primo nodo inserito
	nodo *t;  // tail, il puntatore all'ultimo nodo inserito
}coda;

coda coda_new(void);
coda coda_in(coda, float);
float coda_get(coda);
coda coda_del(coda);
void coda_mostra(coda);
int coda_empty(coda);

int main(){
	coda q = coda_new();

	for(int i = 0; i < 10; i++){
		q = coda_in(q, i);
	}
	
    coda_mostra(q);
    printf("Mostro gli elementi della coda mentre la svuoto: ");
	while(coda_empty(q)!=1){
		printf("%.2f, ", coda_get(q));
		q = coda_del(q);
	}
    printf("\n");
}

coda coda_new(void) {
	coda c = {NULL, NULL};
	return c;
}

int coda_empty(coda c){
	if (c.h == NULL)
		return 1;
	return 0;
}

coda coda_in(coda c, float e){
    nodo *n = malloc(sizeof(nodo));
    n->dato=e;
    n->succ=NULL;
    if(coda_empty(c)==1){
        c.h=n;
        if(c.t==NULL)
            c.t=c.h;
    }
    else{
        c.t->succ=n;
        c.t=c.t->succ;
    }
    
	return c;
}

float coda_get(coda c){
	if(coda_empty(c)==1){
        return -1;
    }
	return c.h->dato;
}

coda coda_del(coda c){
	if (coda_empty(C)==1)  // la coda è vuota
		return c;
	nodo *p=c.h;
    c.h=p->succ;
    free(p);
    if ( coda_empty(c)==1 ) // nel caso ora la coda sia vuota...
        c.t = NULL;
		
	return c;
}

void coda_mostra(coda x){
	nodo *p=x.h;

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