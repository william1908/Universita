#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <C:\Users\damic\OneDrive\Desktop\Universita\Programmazione_dei_calcolatori\c\cerca_tipo.h>

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