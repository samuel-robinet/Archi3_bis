//Includes
#include <stdio.h>
#include <stdlib.h>
//Declarations
void Stack_print(Stack *stk);
Stack * Stack_new();
void Stack_push(Stack *stk, int nb);
Stack_pop(Stack *stk, int* res_ptr);
void Stack_print(Stack *stk);
//Implementation
int main() {



}

struct Element{
    int data;
    Element *next;
}
typedef struct Element Element;

//La structure de pile donne simplement le premier élément:
struct Stack{
    Element *head;
};
typedef struct Stack Stack;

//Voici une fonction qui permet de créer un élément:
Element * Element_new(int value){
    Element * ptr = (Element *) malloc(sizeof(Element));
    ptr->data = value;
    return ptr;
}

//Et une fonction qui permet de créer une pile:
Stack * Stack_new(){
    Stack * ptr = (Stack *) malloc(sizeof(Stack));
    ptr->head = NULL;
    return ptr;
}
//Insérer un nombre dans la pile
void Stack_push(Stack *stk, int nb){
    if(stk==NULL){
        perror("Stack pointeur");
        exit(1);
    }
    Element * EE= Element_new(nb);
    EE-> next = stk->head;
    stk->head=EE;
}
//Depiler l'element au sommet
Stack_pop(Stack *stk, int* res_ptr){
    if(stk==NULL){
        perror("Stack pointeur");
        exit(1);
    }
    if(res_ptr==NULL){
    perror("Stack pointeur");
    exit(1);
    }
    if(stk->res_ptr==null){
    perror("Stack pointeur");
    exit(-1);
    }
    *res_ptr=stk->head->data;
    Element * EE = stk->head;
    stk->head=stk->head->next;
    free(EE);
}
void Stack_print(Stack *stk){
    printf("La pile : \n");
    Element * EE = stk->head;
    while(EE!=NULL){
        printf("%d \n", EE->data);
        EE = EE->next;

    }
    printf("=================== \n")


}
