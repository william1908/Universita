#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *k="William";
    int h = 0;
    
    while ( *k != '\0' ){
        h += *k;
        printf("%d %d\n", h, *k);
        k++;
    }
    printf("%d %d\n", h, *k);
    return 0;
}