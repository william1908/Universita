#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Inverti(char a[]){
    int n = strlen(a);
    char b[n];

    for(int i=0; i<n; i++){
        b[n-i-1]=a[i];
    }
    for(int i=0; i<n; i++){
        a[i]=b[i];
    }
    
}
int Palindroma(char a[]){
    int n= strlen(a);
    for(int i; i<n/2; i++){
        if(a[i]!=a[n-i-1]){
            return 0;
        }
    }
    return 1;
}
int count_vocali(char a[]){
    int n= strlen(a);
    int c=0;
    for(int i=0; i<n; i++){
        if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u'||a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U'){
            c++;
        }
    }
    return c;
}

char *str_cat(char a[], char b[]){
    int n1 = strlen(a);
    int n2= strlen(b);
    int n= n1+n2+1;
    char *c=malloc(sizeof(char)*n);
    int i=0;
    for(; i<n1; i++){
        c[i]=a[i];
    }
    for(int j=0; j<n2; j++, i++){
        c[i]=b[j];
    }
    c[i]='\0'; 
    return c;
}



int main(){
    char a[]="ciao";
    printf("%s\n", a);
    Inverti(a);
    printf("%s\n", a);

    char b[]="c";
    if(Palindroma(b)==1){
        printf("La stringa e' palindroma\n");
    }
    else{
        printf("La stringa non e' palindroma\n");
    }
    char c[]="William D'Amico";
    printf("Il nome contiene %d vocali\n", count_vocali(c));
    
    Inverti(a);
    char *d= str_cat(a, c);
    printf("La stringa concatenata e': %s\n", d);
    printf("%d\n", strlen(d));
    return 0;
}

