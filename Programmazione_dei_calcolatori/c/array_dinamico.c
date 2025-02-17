#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float *a;
    int c;  /* capacita'  */
    int n;  /* dimensione, numero di elementi */
}lista_f;

lista_f init();
lista_f append(lista_f, float);

int main(){
    lista_f lista=init();

    for(int i = 0; i < 20; i++){
        lista = append(lista, i*10);
        printf("%d, %d\n", lista.n, lista.c);
    }
    
    for(int i = 0; i < 20; i++){
        printf("%f\n", lista.a[i]);
    }
    return 0;
}

lista_f init(){
    lista_f lista_vuota={NULL, 0, 0};
    return lista_vuota;
}

lista_f append(lista_f l, float f){
    if (l.n == l.c) {
        l.c = 2*(l.c+1); 
        l.a = realloc( l.a, l.c*sizeof(float) );
    }

    l.a[l.n]=f;
    l.n++;
    return l;


}