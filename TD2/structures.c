//Includes
#include <stdio.h>
#include <stdlib.h>
//Declarations

//Implementation
int main() {
    Coordonnees2D point1;
    Coordonnees2D *ptr ;

    point1.positionX=10;

    ptr = &point1 ;
    ptr->positionX ;// OK !
    assert( ptr->positionX == point1.positionX); // un test toujours vrai


}

typedef struct _coordonnees2D Coordonnees2D {
    int positionX ;
    int positionY ;
}
