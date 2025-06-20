#include <stdio.h>



int main(){
    char a[100]={11};
    char *p=&(a[50]);
    printf("%d", p);
    return 0;
}

