#include <stdio.h>

int Ricerca_Binaria(int a[], int n, int k){
    int lx=0, rx=n-1;
    if(k<a[lx])
        return -1;
    if(k>a[rx])
        return -1;
    while(lx<=rx){
        int cx= (lx+rx)/2;
        if(k==a[cx]){
            return cx;
        }
        if(k<a[cx]){
            rx=cx-1;
        }
        if(k>a[cx]){
            lx=cx+1;
        }
    }
    return -1;
}

int main(){
    int a[10]={0,1,2,3,4,5,6,7,8,9};

    printf("%d", Ricerca_Binaria(a, 10, 100));
}