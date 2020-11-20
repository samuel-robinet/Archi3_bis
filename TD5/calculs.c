#include  <stdio.h>
#include <stdlib.h>
#include  <setjmp.h>

int calculs(int i, int j, int k) {
    afficher(Calculs pour i,j,k);
    if (i==0 || j==0 || k ==0)
        throw exception1;
    if (i+j<k || j+k<i || k+i <j)
        throw exception2;
    if (i+j+k > i*j)
        throw exception3;
    return (i + 2*j + 3*k)/5;
}
static int main() {
    int val1, val2, val3;
    int res;
    while(1) {
        afficher(Donnez trois valeurs a examiner );
        saisir(val1, val2, val3);
        afficher(Les valeurs sont : val1, val2, val3);
        try {
            res = calculs(val1, val2, val3);
        }
        catch (exception1){
            afficher(Valeur zero parmi : val1, val2, val3);
        }
        catch (exception2){
            afficher(Probleme triangulaire :  val1, val2, val3);
        }
        catch (exception3){
            printf("Probleme ecart :   val1, val2, val3);
        }
    } //while
}
