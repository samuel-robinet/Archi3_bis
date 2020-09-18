//Includes
#include <stdio.h>
#include <stdlib.h>
//Declarations
int maVariableGlobale = 0;
void test();
void permuter(int *adr_i, int *adr_j);
int length(char* chaine);
void tableau1();
int strcomp(char* chaine1,char* chaine2);
void strcpy(char* dest,char* src);
//Implementation
int main(){
	//test();
	int v1=2;
	int v2=10;
	//permuter(&v1,&v2);
	//tableau1();
	int a=length("Bonjour");
	printf("%i \n",a);

	
	printf("%i \n",strcomp("Bonjourdf","Bonjour"));
	/* char* maloc;
	maloc=malloc(length(src)*sizeof(char));*/

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

	printf(" %d, %d \n",*adr_i,*adr_j) ;
}

void tableau1(){
	int tab[10] ; // un tableau de 10 cases de int
	int *adr_i ; // declarer une variable qui contient une @ d'un int.
	adr_i = tab ; //tab contient l'adresse de la premiere variable de la sequence.

	printf(" %p \n",adr_i) ; // affiche l'adresse
}

int length(char* chaine){
	int i=0;
	while(chaine[i]!='\0'){
		i++;
	}
	return i;
}
int strcomp(char* chaine1,char* chaine2){
	int a=length(chaine1);
	int b=length(chaine2);
	int c=1;
	int i=0;

	if (a!=b){
		c=0;
	}
	while(chaine1[i]<a && chaine2[i]<b && c==1){
		if(chaine1[i]==chaine2[i]){
			c=1;

		}
		else{
			c=0;
		}
				
		i++;
	}
	return c;

	
}

int void strcpy(char* dest,char* src){
	int a=length(chaine1);
	int b=length(chaine2);
	int c=1;
	int i=0;

	while(chaine1[i]<a && chaine2[i]<b && c==1){
		if(chaine1[i]==chaine2[i]){
			c=1;

		}
		else{
			c=0;
		}
				
		i++;
	}
	return c;

	
}



/* 
 Globale: 0x55b586329014 
 Locale: 0x7ffc978830c7 
 Taille de char: 1 
 Taille de int: 4 
 Taille de pointeur de char: 8 
 Taille de pointeur de int: 8 
*/