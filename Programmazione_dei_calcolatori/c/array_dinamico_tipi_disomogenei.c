#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\damic\OneDrive\Desktop\Universita\Programmazione_dei_calcolatori\c\cerca_tipo.h> //includo la libreria per aver eun codice più pulito
#include <string.h>

typedef struct  {
    char tipo; /* 'i' intero; 'f' float; 's' stringa */
    void *dato;
} elemento;



struct lista {
    elemento *a;
    int c;  /* capacita'  */
    int n;  /* dimensione, numero di elementi */
};
typedef struct lista lista;


lista init();
lista append(lista, elemento);
void mostra(lista);
lista pop(lista);
lista insert(lista, elemento, int);
lista delete(lista, int);

elemento intero(int);
elemento fpoint(float);
elemento stringa(char*);

int main(int n, char *args[]){
    lista L = init();
    char buffer[1024];

    for(int i=1; i<n; i++){
        strcpy(buffer, args[i]);
        switch (Trova_tipo(buffer)){
            case 'i':{
                int a;
                sscanf(buffer, "%d", &a);
                L = append(L, intero(a) );
                break;
            }
            case 'f':{
                float f;
                sscanf(buffer, "%f", &f);
                L = append(L, fpoint(f) );
                break;
            }
            default:{
                char *s =  malloc(sizeof(char)*(strlen(buffer)+1));
                strcpy(s, buffer);
                L = append(L, stringa(s) );
                break;
            }
        }
    }

    mostra(L);
    int p;
    printf("Inserisci elemento e posizione nel formato 'elemento posizione' da inserire nell'array: ");
    scanf("%s %d", &buffer, &p);

        switch (Trova_tipo(buffer)){
            case 'i':{
                int a;
                sscanf(buffer, "%d", &a);
                L = insert(L, intero(a), p );
                break;
            }
            case 'f':{
                float f;
                sscanf(buffer, "%f", &f);
                L = insert(L, fpoint(f), p );
                break;
            }
            default:{
                char *s =  malloc(sizeof(char)*(strlen(buffer)+1));
                strcpy(s, buffer);
                L = insert(L, stringa(s), p );
                break;
            }
        }
    mostra(L);
  
    

    L=delete(L, 3);
    mostra(L);

    /*while(L.n > 0){
        L = pop(L);
        mostra(L);
    }
    mostra(L);*/

    return 0;

}
lista init(){
    lista lista_vuota = {NULL, 0, 0};
    return lista_vuota;
}

lista delete(lista L, int p){
    if(p<0){
        p=0;
    }
    for(int i = p; i<L.n-1; i++){
        L.a[i]=L.a[i+1];
    }
    L=pop(L);
    return L;
}

lista append(lista L, elemento e){
    if (L.n == L.c) {
        L.c = 2*(L.c+1); 
        L.a = realloc( L.a, L.c*sizeof(elemento) );
    }
    
    L.a[L.n] = e;
    L.n++;
    
    return L;
}

void mostra(lista L){
    int i;
    
    printf("==================================\n");
    
    for(i = 0; i < L.n; i++){
        switch  (L.a[i].tipo) {
            case 'i':
                printf("%d\n", *((int*)L.a[i].dato) );
                break;
            case 'f':
                printf("%.2f\n", *((float*)L.a[i].dato) );
                break;
            case 's':
                printf("%s\n", (char*)L.a[i].dato );
                break;
        }
    }
    
    printf("dimensione %d, capacita' %d\n", L.n, L.c);
}

lista pop(lista L){
    if(L.n > 0 ){
        L.n--;
        if (L.n < L.c/4){
            L.c = L.c/2;
            L.a = realloc(L.a, (L.c)*sizeof(elemento)); 
        }
        if (L.a[L.n].tipo != 's')
            free(L.a[L.n].dato);
    }
    return L;
}

elemento intero(int d){
    elemento e = {'i', NULL};
    
    e.dato = malloc(sizeof(int));
    *((int*)e.dato) = d;

    //(int*)e.dato converte il valore di e.dato (che è un void*) in un puntatore a int.
    //*((int*)e.dato) accede alla memoria puntata e la tratta come un int
    
    return e;
}

elemento fpoint(float d){
    elemento e = {'f', NULL};
    
    e.dato = malloc(sizeof(float));
    *((float*)e.dato) = d;

    //(float*)e.dato converte il valore di e.dato (che è un void*) in un puntatore a float.
    //*((float*)e.dato) accede alla memoria puntata e la tratta come un float
    
    return e;
}

elemento stringa(char *d){
    elemento e = {'s', NULL};
    e.dato = d;
    return e;
}

lista insert(lista L, elemento e, int p){
    if(p<0){
        p=0; //se la posizione dove inserire l'elemento è negativa, allora verrà inserito in posizione 0
    }
    L=append(L, e);

    for(int i=L.n-1; i>p; i--){
        L.a[i]=L.a[i-1];
        L.a[i-1]=e;
    }
    return L;
}
