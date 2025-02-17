#include <stdio.h>
#include <stdlib.h>
int Distribuzione(int a[], int sx, int dx ){
    int i = sx + 1;
    int j = dx;
    int finale = sx;
    int temp;
    while (i <= j){
        while (i <= j && a[i] <= a[sx]){
            finale = i;
            i++;
        }
        while (i <= j && a[j] > a[sx]){
            j--;
        }
        if  (i <= j){
            temp = a[i];
            a[i] = a[j];
            a[j]= temp;
        }
    }
    temp = a[sx];
    a[sx] = a[finale];
    a[finale]= temp;
    return finale;
}

void OrdinamentoPerDistribuzione(int a[], int sx, int dx){
    if (sx<dx){
        int pos=Distribuzione(a, sx, dx);
        OrdinamentoPerDistribuzione(a, sx, pos-1);
        OrdinamentoPerDistribuzione(a, pos+1, dx);
    }
}
void BubbleSort(int a[], int n){
    int terminato;
    int temp;
    for(int i=0; i<n; i++){
        terminato = 1;
        for(int j=0; j<n-1-i; j++){
            if (a[j] > a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                terminato = 0;
            }
        }
        if (terminato==1){
            break;
        }
    }
}

void merge(int arr[], int lx, int cx, int rx) {
    int i = lx, j = cx + 1, k = 0;
    int n = rx - lx + 1;
    int c[n];

    while (i <= cx && j <= rx) {
        if (arr[i] <= arr[j]) {
            c[k] = arr[i];
            i++;
            k++;
        } 
        else{
            c[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= cx) {
        c[k] = arr[i];
        i++;
        k++;
    }
    while (j <= rx) {
        c[k] = arr[j];
        j++;
        k++;
    }
    for (i = lx, k = 0; i <= rx; i++, k++) {
        arr[i] = c[k];
    }
}

void mergeSort(int a[], int lx, int rx) {
    if (lx < rx) {
        int c = (lx + rx) / 2;
        mergeSort(a, lx, c);
        mergeSort(a, c + 1, rx);
        merge(a, lx, c, rx);
    }
}

int main(){
    int a[15] = {10, 21, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10};
    OrdinamentoPerDistribuzione(a, 0, 14);
    for( int i=0; i<15; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    int b[15] = {10, 21, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10};
    BubbleSort(b, 15);
    for( int i=0; i<15; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    int c[15] = {10, 21, 30, 34, 34, 38, 11, 13, 16, 17, 19, 0, 0, 10, 10};
    mergeSort(c, 0, 14);
    for( int i=0; i<15; i++){
        printf("%d ", c[i]);
    }
    printf("\n");
    return 0;
}