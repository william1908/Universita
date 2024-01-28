#include<stdio.h>
#include<stdlib.h>

struct nodo{
	int info ;
	struct nodo *succ ;
	struct nodo *prec;
};
typedef struct nodo nodo ;



void stampaLista(nodo *x){
	nodo *p=x;
	while(p!=NULL){
		printf("%d -> ", p->info);
		p=p->succ;
	}
	printf("//\n");

}

nodo *lista_init(nodo *x, int l){
	nodo *p, *n;
	for(int i=0; i<l; i++){
		if(x==NULL){
			n = malloc(sizeof(nodo));
			n->info = i; 
			n->succ = NULL;
			n->prec=NULL;
			x=n;
		}
		else{
			p=x;
			while(p->succ!=NULL){
				p=p->succ;
			}
			n = malloc(sizeof(nodo));
			n->info = i;
			n->succ = NULL;
			n->prec = p;
			p->succ = n;
		}
	}
	return x;
}
nodo *Sotto_lista(nodo *x, int pos, int n){
	int i=0;
	nodo *p=x;
	while(i<pos && p!=NULL){
		i++;
		p=p->succ;
	}
	i=0;
	nodo *q;
	nodo *z = malloc(sizeof(nodo));
	z->prec=NULL;
	z->info=p->info;
	z->succ=NULL;
	q=z;
	nodo *y=q;
	while(i<n-1 && p!=NULL){
		z = malloc(sizeof(nodo));
		p=p->succ;
		z->info = p->info;
		z->succ = NULL;
		z->prec = y;
		y->succ = z;
		y=y->succ;
		i++;

	}
	return q;
}

int lunghezzaLista(nodo *x){
	int l=0;
	nodo *p=x;
	while(p!=NULL){
		l++;
		p=p->succ;
	}
	return l;
}

nodo *primoPari(nodo *x){
	if(x==NULL){
		return NULL;
	}
	nodo *p=x;
	while(p!=NULL){
		if(p->info%2==0 && p->info!=0){
			return p;
		}
		p=p->succ;
	}
	return NULL;
}

nodo *elimina_parte_Lista(nodo *x, int l){
	int i=0;
	while(i<l && x!=NULL){
		x=x->succ;
		i++;
		x->prec=NULL;
	}
	return x;
}


nodo *Lista_reverse(nodo *x){
	nodo* temp = NULL;
    nodo* current = x;

    while (current != NULL) {
        temp = current->prec;
        current->prec = current->succ;
        current->succ = temp;

        current = current->prec;
    }

    // Se temp è non nullo, allora era l'ultimo nodo, quindi ora è il nuovo inizio
    if (temp != NULL) {
        x = temp->prec;
    }

    return x;
}

nodo *Pop(nodo *x){
	 if (x == NULL) {
        return NULL;  // La lista è vuota, nulla da eliminare
    }

    nodo* p = x;
    while (p->succ != NULL) {
        p = p->succ;
    }

    if (p->prec != NULL) {
        p->prec->succ = NULL;  // Elimina l'ultimo elemento
    } else {
        x = NULL;  // L'ultimo elemento era anche il primo (la lista aveva un solo elemento)
    }

    free(p);  // Libera la memoria dell'elemento eliminato
    return x;
}


int main(){
	nodo *n=NULL;
	n=lista_init(n, 10);
	stampaLista(n);
	n=Lista_reverse(n);
	stampaLista(n);

	n=Pop(n);
	stampaLista(n);

	nodo *q=Sotto_lista(n, 2, 3);
	stampaLista(q);


	/*printf("La lista e' lunga %d nodi\n",lunghezzaLista(n));
	nodo *x=primoPari(n);
	if(x!=NULL)
		printf("Il primo numero pari della lista e' %d\n", x->info);
	else
	printf("Non ci sono numeri pari nella lista\n");
	n=elimina_parte_Lista(n, 2);
	printf("La lista ridotta e'':\n");
	stampaLista(n);
	n=ordinaLista(n);
	printf("La lista ordinata e':\n");
	stampaLista(n);

	nodo *m=NULL;
	m=lista_init(n, 10);

	nodo *o=merge(n, m);
	stampaLista(o);*/
	return 0;
}

/*nodo *ordinaLista ( nodo *x){
	if (x == NULL || x->succ == NULL)
        return x;

    nodo* p = NULL;  // Lista ordinata
    nodo* tmp = x;    // Nodo corrente da inserire

    while (tmp != NULL) {
        nodo* next = tmp->succ;  // Salva il prossimo nodo prima di staccare tmp

        // Inserimento di tmp nella lista ordinata p
        if (p == NULL || tmp->info < p->info) {
            tmp->succ = p;
            p = tmp;
        } else {
            nodo* current = p;
            while (current->succ != NULL && current->succ->info < tmp->info) {
                current = current->succ;
            }
            tmp->succ = current->succ;
            current->succ = tmp;
        }

        tmp = next;  // Passa al prossimo nodo nella lista non ordinata
    }
    return p;
}

nodo *merge ( nodo *l1 , nodo *l2 ){
	nodo *risultato = NULL ;
	nodo *new = NULL ;
	int primavolta = 1;

	while (( l1 != NULL )&&( l2 != NULL )) {
		if ( primavolta ){
			new = malloc ( sizeof (nodo *));
			risultato = new ;
			primavolta =0;
		}
		else{
			new -> succ = malloc ( sizeof ( nodo * ));
			new = new -> succ ;
		}
		if (l1 -> info <l2 -> info ){ 
			new -> info =l1 -> info ; 
			l1 =l1 -> succ ; 
		}
		else{ 
			new -> info =l2 -> info ; 
			l2 =l2 -> succ ; 
		}
	}

	while ( l1 != NULL ){
		new -> succ =malloc ( sizeof (nodo *));
		new = new -> succ ;
		new -> info = l1 -> info ;
		l1 = l1 -> succ ;
	}
	while ( l2 != NULL ){
		new -> succ =malloc ( sizeof (nodo *));
		new = new -> succ ;
		new -> info = l2 -> info ;
		l2 = l2 -> succ ;
	}

	if ( new != NULL ) 
		new -> succ = NULL ;
	return risultato ;
}*/
