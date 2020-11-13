#include <stdlib.h>     /* atol */
#include <stdio.h> /*fprintf*/
#include <setjmp.h>


static jmp_buf env;

static void recEstPremier(long valeur, long diviseur){
    if(diviseur==1){
        longjmp(env, 1);
    }

    if(valeur%diviseur == 0){
        longjmp(env, 2);
    }
    else{
        recEstPremier(valeur, diviseur-1);
    }
}

static void estPremier(long valeur){
    if(valeur == 1){
        longjmp(env, 1);
    }
    else{
        recEstPremier(valeur, valeur-1);
    }
}

int main(int argc, char** argv){
    if(argc!=2){
        printf("Usage %s <entier>\n",argv[0]);
        exit(-1);
    }

    long valeur = atol(argv[1]);
    if(valeur==0){
        printf("Usage %s <entier !=0>\n",argv[0]);
    }
    valeur = (valeur<0)?-valeur:valeur; //abs

    int premier;
    switch(setjmp(env)){    //Encrage
        case 0 : // on est parti
            estPremier(valeur);
            printf("normalement on ne vient pas ici");
            break;
        case 1 : // retour pour premier
            printf("La valeur %s est un nombre premier \n", argv[1]);
            break;
        case 2 : //retour pour non premier
            printf("La valeur %s n'est pas un nombre premier \n", argv[1]);
            break;
    }
    fprintf(stdout,"estPremier ?: %d\n",premier);
}