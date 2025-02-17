#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char Trova_tipo(char *a){
    //la funzione prende in input una stringa e restituisce 'i' se la stringa è un intero, 'f' se è un float e 's' se è una stringa
    int p=0;
    int i=0;
    while (i<strlen(a)){
        if(a[i]<'0' || a[i]>'9'){
            if(a[i]=='.'){
                p++;
                if(p>1){
                    return 's';
                }
            }
            else{
                return 's';
            }
        }
        i++;
    }
    if(p==1){
        return 'f';
    }
    else{
        return 'i';
    }
    //Complessità temporale O(n), dove n è la lunghezza della stringa, nel caso peggiore scorre tutta la stringa
    //Complessità spaziale O(1), uilizzo solo 2 variabili intere
}
int main (int n, char *args[]){
    char buffer[1024];
    for(int i=1; i<n; i++){
        strcpy(buffer, args[i]);
        switch (Trova_tipo(buffer)){
            case 'i':{
                int a;
                sscanf(buffer, "%d", &a);
                printf("%d\n", a);
                break;
            }
            case 'f':{
                float b;
                sscanf(buffer, "%f", &b);
                printf("%f\n", b);
                break;
            }
            default:{
                char *s =  malloc(sizeof(char)*(strlen(buffer)+1));
                strcpy(s, buffer);
                printf("%s\n", s);
                break;
            }
        }
    }
    
    return 0;
}