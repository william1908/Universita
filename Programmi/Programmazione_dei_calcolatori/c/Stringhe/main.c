#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int tiposeq;

struct sequenza {
	tiposeq *a;
	int n; // numero di elementi effettivi in a
	int c; // capacità di a, ovvero quanto spazio c'è (n <= c)
};
typedef struct sequenza sequenza;
sequenza nuova_sequenza( ){
	/*
	 * Ritorna una nuova sequenza vuota
	 * */
	 
	sequenza v = {NULL, 0, 0};
	 
	return v;
}
sequenza append_sequenza(sequenza v, tiposeq x) {
	int n = v.n;
	
	if ( v.n == v.c ){ // tutti gli elementi dell'array sono occupati
		v.c = 2*v.c+1;
		v.a = realloc(v.a, sizeof(tiposeq)*v.c);
	}
	
	v.a[n] = x;
	v.n ++;
	
	return v;
}
void mostra_sequenza(sequenza v){
	int i;
	for(i = 0; i < v.n; i++){
		printf("%.2f ", (float)v.a[i]);
	}
	printf("\n");
}

char change_case(char);

char *cat(char*, char*);
sequenza trova_vocali(char*);

int len(char *s){
	/*
	 * Ritorna il numero di caratteri nella stringa s (escluso il finestringa)
	 * */

	int c = 0;
	for(int i = 0; s[i] != '\0'; i++){
		c++;
	}
	return c;
}

void bubble_Sort(int n, char *a[]){
    char temp[50];
    for (int i=0; i<n-1; i++) {
        for (int j = 0; j<n-1-i; j++) {
            if (strcmp(a[j], a[j+1]) > 0) {
                strcpy(temp, a[j]);
                strcpy(a[j], a[j + 1]);
                strcpy(a[j+1], temp);
            }
        }
    }
}


int main(int n, char *a[]){
	char c = 65, d = 'u';

	c = c+1; // ASCII

	printf("%d, %c\n", c, c);
	printf("%d, %c\n", d, d);

	printf("%c, %c, %c\n", change_case('f'), change_case('H'),
		change_case('+') );

	char s[] = {'p', 'y', 't', 'h', 'o', 'n', '\0'};
	char s1[] = "python";

	printf("%s\t%s\n", s, s1);

	printf("%d\n", sizeof(s1));

	s1[2] = '\0';

	printf("%s\n", s1);

	printf("%d\n", sizeof(s1));

	printf("%d\n", len(s1));

	printf("===================================\n");

	bubble_Sort(n, a);

    for (int i = 0; i < n; i++) {
        printf("%s\n", a[i]);
    }

	printf("===================================\n");

	char b[] = "programmazione ";
	char e[] = "dei calcolatori";
	
	char *f = cat(b, e);
	if (e != NULL)
		printf("%s\n", f); 

	sequenza m = trova_vocali(f);  //restiuisce una sequenza in cui sono salvati gli indice di dove si trovano le vocali
	mostra_sequenza(m);

	
}

sequenza trova_vocali(char *x){
	sequenza s = nuova_sequenza();
	int i = 0;
	
	while( x[i] != '\0' ){
		if (x[i] == 'a' || x[i]=='e' ){ /* aggiungere i o e u*/
			s = append_sequenza(s, i);
		}
		i++;
	}
	
	return s;
}

char *cat(char *x, char *y){
	/*
	 * ritorna una nuova stringa dalla concatenazione di x ed y
	 * 
	 * oppure NULL non e' possibile allocare spazio per la nuova stringa
	 * */
	char *w;
	int n = len(x);
	int m = strlen(y); /* come len, ma nella libriria string  */
	int i;
	
	w = (char*)malloc((n+m+1)*sizeof(char));
	
	if (w != NULL) {
		for(i = 0; i < n; i++){
			w[i] = x[i];
		}
		for(; i < n+m; i++){
			w[i] = y[i-n];
		}
		w[i] = '\0'; /* perche' i e' n+m*/
	}
		
	return w;
}

char change_case(char c){
	/*
	 * se c e' maiuscolo ritorna il minuscolo e viceversa
	 * se c non e' una lettera ritorna c
	 * */

	 if ( c >= 'a' && c <= 'z'){
		return 'A'+c-'a';
	 }
	 if ( c >= 'A' && c <= 'Z'){
		return 'a'+c-'A';
	 }
	 return c;
}
