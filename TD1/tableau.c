// section pour inclure les en-tete
#include <stdio.h>
#include <stdlib.h>
//section pour delarer les fonctions et variables globales
#define TAILLE 5
int main();
void tri();
void affiche();
// variable globale
int tableau[TAILLE];
//----------------------
//section pour realiser les fonctions
// la fonction main
//void tri();
int main(){
	int a = 0;
	int i = 0;
	for(int i = 0 ; i < TAILLE; i ++){
		printf("donnez un entier ?\n");
		scanf("%d",&a);
		tableau[i] = a;
	}
	affiche();
	tri();
	affiche();
}
void affiche(){
	int i ;
	printf("DEBUT TABLEAU\n");
	for(i=0;i<TAILLE;i++){
		printf("[%d] = %d \n",i,tableau[i]);
		}
		printf("FIN TABLEAU\n");
	}
	// la fonction de tri
void tri(){
	int i = 0;
	int j = 0;
	int c = 0;
	for(j=0;j< TAILLE;j++){
		for(i=0;i< TAILLE-1;i++){
			if ( tableau[i] > tableau[i+1] ){
			c = tableau[i];
			tableau[i] = tableau[i+1];
			tableau[i+1] = c;
			}
		}
	}
}