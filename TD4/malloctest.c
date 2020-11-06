#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <unistd.h>


#define ALIGNMENT 8
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~(ALIGNMENT-1))
#define ENTETE_SIZE (ALIGN(sizeof(bloc_entete)))
#define TAILLE_MAX 1024

void* blocinfo(void* ptr);
void* myalloc(size_t t);
void* myfree(void* ptr);



typedef struct bloc_entete {
    size_t taille; //taille du bloc utilisateur
    unsigned short libre : 1 ; //drapeau de 1 bit qui indique si le
//bloc est libre ou utilise: 1 libre, 0 utilise.
} bloc_entete ;

void* blocinfo(void* ptr){
    bloc_entete* bloc_total= (bloc_entete*) ((char*)ptr - ENTETE_SIZE);
    printf("pointeur bloc %p \n, pointeur donnees %p \n, taille totale: %ld, \nbloc libre ?: %d\n",
           bloc_total,
           ptr,
           bloc_total->taille,
           bloc_total->libre);
}

int main(int argc, char* argv[])
{
    printf("[%s] lancee\n",argv[0]);
    //allocation d'un tableau
    myalloc(8);
    srand (time(NULL));
    int taille = 1 + (rand() % TAILLE_MAX);
    int* buffer = (int*)myalloc(taille*sizeof(int));
    printf("allocation de %d entiers (%d octect par entier) à: %p \n",taille,sizeof(int),(void*)buffer);
    int i ;
    for( i = 0; i < taille ; i++)
    {
        buffer[i] = taille-i;
    }
    for( i = 0; i < taille ; i++)
    {
        assert(buffer[i] == taille-i);
    }
    blocinfo(buffer);
    myfree(buffer);
    blocinfo(buffer);
    printf("[%s] termine\n",argv[0]);
}

void* myalloc(size_t t){ //void* pointe vers une zone memoire
    //sbrk(8) deplace brk de 8
    /*
    void* pte=sbrk(ENTETE_SIZE);
    struct bloc_entete entete;
    entete.taille=t;
    entete.libre=0;*/

    void* pt1=sbrk(ENTETE_SIZE+ALIGN(t));
    bloc_entete* pte=(bloc_entete*)pt1;
    pte->taille=ALIGN(t);
    pte->libre=0;

    char* ptc=(char*)pte;
    ptc=ptc+ENTETE_SIZE;
    return ptc;

}

void* myfree(void* ptr){
    bloc_entete* bloc= (bloc_entete*)((char*) ptr- ENTETE_SIZE);
    bloc->libre=1;
}
