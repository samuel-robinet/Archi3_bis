#include <stdlib.h>
#include <stdio.h>
#include <setjmp.h>
static jmp_buf env;

int calculs(int i, int j, int k){
    printf("Calcul pour %d, %d, %d\n", i, j, k);
    if(i==0 || j==0 || k==0)
        longjmp(env, 1);
    if (i+j<k || j+k<i || k+i <j)
        longjmp(env, 2);
    if (i+j+k > i*j)
        longjmp(env, 3);
    return (i + 2*j + 3*k)/5;
}

int main(int argc, char** argv) {
    int val1, val2, val3;
    int res;
    while(1){
        printf("Saisir 3 valeurs :\n");
        scanf("%d %d %d", &val1, &val2, &val3);
        printf("Les valeurs sont : %d, %d, %d\n", val1, val2, val3);

        switch(setjmp(env)){  //Encrage
            case 0 : //..
                res = calculs(val1, val2, val3);
                printf("Resultat calcul :  %d\n", res);
                break;
            case 1 : // retour
                printf("Valeur zéro parmi les 3 valeurs \n");
                break;
            case 2 : //retour
                printf("Problème triangulaire entre les 3 valeurs \n");
                break;
            case 3 : //retour
                printf("Problème ecart entre les 3 valeurs \n");
                break;
        }
    }
}