#include <stdio.h>
#include <C:\Users\damic\OneDrive\Desktop\Universita\Programmazione_dei_calcolatori\c\lista_concatenata.h>

int Palindroma(lista a){
    if(a==NULL || a->succ==NULL){
        return 1;
    }
    nodo *q=a;
    nodo *h=a;
    while(q->succ!=NULL){
        q=q->succ;
    }
    while(q->dato==h->dato && q!=h && h->prec!=q){
        q=q->prec;
        h=h->succ;
    }
    if(q->dato==h->dato)
        return 1;
    else 
        return 0;
}

int main(){
    lista L=lista_vuota();

    L=in_c(L, 1);
    L=in_c(L, 2);
    L=in_c(L, 3);
    L=in_c(L, 2);
    L=in_c(L, 1);

    lista_mostra(L);

    if(Palindroma(L)==1)
        printf("La lista e` palindroma");
    else
        printf("La lista non e` palindroma");

    return 0;
}