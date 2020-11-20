#include <setjmp.h>
#include <stdio.h>

static jmp_buf env;

#define TRY do{ switch( setjmp(env) ){ case 0:
#define CATCH(x) break; case x:
#define ETRY } }while(0)
#define THROW(x) longjmp(env, x)


#define EXEPTION_UNE (1)
#define EXEPTION_DEUX (2)
#define EXEPTION_TROIS (3)


int calculs(int i, int j, int k){
    printf("Calcul pour %d, %d, %d\n", i, j, k);
    if(i==0 || j==0 || k==0)
        THROW(EXEPTION_UNE); // pareil que longjmp(env, 1) dans la Q1
    if (i+j<k || j+k<i || k+i <j)
        THROW(EXEPTION_DEUX); // pareil que longjmp(env, 2);
    if (i+j+k > i*j)
        THROW(EXEPTION_TROIS); // pareil que longjmp(env, 3);
    return (i + 2*j + 3*k)/5;
}

int main(int argc, char** argv) {

    int val1, val2, val3;
    int res;

    printf("Saisir 3 valeurs :\n");
    scanf("%d %d %d", &val1, &val2, &val3);
    printf("Les valeurs sont : %d, %d, %d\n", val1, val2, val3);

    TRY {
                res = calculs(val1, val2, val3);
                printf("Calcul : %d\n", res);
            }CATCH (EXEPTION_UNE){
                printf("Valeur zéro parmi les 3 valeurs \n");
            }CATCH (EXEPTION_DEUX){
                printf("Problème triangulaire entre les 3 valeurs\n");
            }CATCH (EXEPTION_TROIS) {
                printf("Problème d'ecart entre les 3 valeurs \n");
            }
    ETRY;
}
