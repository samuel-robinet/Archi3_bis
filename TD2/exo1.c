//Includes
#include <stdio.h>
#include <stdlib.h>
//Declarations
int maVariableGlobale = 0;
void test();
//Implementation
int main(){
	//test();
	int v1=2;
	int v2=10;
	permuter(&v1,&v2);

	}

void test(){
	char maVariableLocal = 'X';
	char *p_c;
	int *p_i;
	p_i = &maVariableGlobale;
	printf(" Globale: %p \n", p_i);
	p_c = &maVariableLocal ;
	printf(" Locale: %p \n", p_c);
	printf(" Taille de char: %ld \n", sizeof(maVariableLocal) ) ;
	printf(" Taille de int: %ld \n", sizeof(maVariableGlobale) ) ;
	printf(" Taille de pointeur de char: %ld \n", sizeof(p_c)) ;
	printf(" Taille de pointeur de int: %ld \n", sizeof(p_i)) ;
}

void permuter(int *adr_i, int *adr_j){
	int a;
 	a = *adr_i;
 	*adr_i = *adr_j;
 	*adr_j = a;

	printf(" %ld, %ld \n",*adr_i,*adr_j) ;
}

/* 
 Globale: 0x55b586329014 
 Locale: 0x7ffc978830c7 
 Taille de char: 1 
 Taille de int: 4 
 Taille de pointeur de char: 8 
 Taille de pointeur de int: 8 
*/