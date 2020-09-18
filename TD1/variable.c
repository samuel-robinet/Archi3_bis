// section pour inclure les en-tete
// précompilation -E, compilation -S et assemblage -c puis édition de lien tout ==> -o
#include <stdio.h>
#include <stdlib.h>
//section pour delarer les fonctions et variables globales
int main();
void addition(int i, int j);
// variable globale
int registre;
//section pour delarer les fonctions
// la fonction main
int main(){
int a = 0;
int b = 0;
printf("donnez un entier ?\n");
scanf("%d",&a);
printf("donnez un entier ?\n");
scanf("%d",&b);
addition(a,b);
printf("%d + %d = %d\n",a,b,registre);
}
// la fonction addition
void addition(int i, int j)
{
registre = i + j;
}