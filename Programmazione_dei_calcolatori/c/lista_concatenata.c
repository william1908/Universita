#include <stdio.h>
#include <stdlib.h>
#include <C:\Users\damic\OneDrive\Desktop\Universita\Programmazione_dei_calcolatori\c\lista_concatenata.h>

int main(){
     lista L=lista_vuota();

    for(int i = 0; i < 10; i++){
        L = in_t(L, i);
    }
    lista_mostra(L);

    L=in_c(L, 11);
    lista_mostra(L);

    L=in_1(L, 32);
    lista_mostra(L);

    L=in_i(L, 40, 5);
    lista_mostra(L);

    L=pop_t(L);
    lista_mostra(L);

    L=pop_1(L);
    lista_mostra(L);

    L=pop_c(L);
    lista_mostra(L);

    L=pop_i(L, 0);
    lista_mostra(L);

    return 0;
}
