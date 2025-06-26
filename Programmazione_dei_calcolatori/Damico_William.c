//Si scriva una funzione in C che riceva in input:
//un array dinamico a di numeri in virgola mobile ( float ), ordinato in modo crescente,
//un intero n che rappresenta la dimensione attuale dell’array,
//e che inserisca nell’array un nuovo elemento con valore pari alla media aritmetica dei due elementi
//consecutivi di a che presentano la massima distanza tra di loro. La funzione deve ritornare l'array
//modificato.
//La funzione dovrà avere il seguente prototipo
//float* inserisci_media(float* a, n);

#include <stdio.h>
#include <stdlib.h>

float* inserisci_media(float* a, int n);

int main(){
    int n=5;
    float *a=malloc(sizeof(float)*n);
    a[0]=12.5;
    a[1]=50.2;
    a[2]=55;
    a[3]=62.3;
    a[4]=70.5;

    a=inserisci_media(a, n);

    for (int i=0; i<n+1; i++){
        printf("%.2f ", a[i]);
    }

    return 0;
}
float* inserisci_media(float* a, int n){
    a=realloc(a,sizeof(float)*(n+1));
    float differenza=(a[1]-a[0]);
    float media=(a[1]-a[0])/2;
    int j=1;
    for(int i=1; i<n-1; i++){
        if(a[i+1]-a[i]>differenza){
            differenza=(a[i+1]-a[i]);
            media=(a[i+1]+a[i])/2;
            j=i+1;
        }
    }
    float temp=a[j+1];
    for(int i=n; i>j; i--){
        a[i]=a[i-1];
    }
    a[j]=media;
    return a;
    /*Complessità spaziale O(1), senza contare l'input a e n, e l'output b*/
    /*Complessità temporale O(n+n+1), quindi O(n)*/
}