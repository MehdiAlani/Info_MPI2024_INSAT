#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct el{
    int val;
    struct el * suivant; 
}el;

typedef el * list;

list cree(){
    return NULL;
}
int tete(list * l){
    if(*l != NULL) return((*l) -> val); 
}
void enfiler(list * f,int val){
    list aux = (list) malloc(sizeof(el));
    aux -> suivant = NULL;
    aux -> val = val;
    if(*f == NULL) {
        *f = aux;
        return;
    }
    list move = *f;
    while(move -> suivant != NULL) move = move -> suivant;
    move -> suivant = aux;
} 
void defiler(list * f){
    if(*f == NULL) return;
    list tmp = (*f) -> suivant;
    free(*f);
    *f = tmp;
}
void empiler(list * p,int val){
    list tmp = (list) malloc(sizeof(el));
    tmp -> suivant = *p;
    tmp -> val = val;
    *p = tmp;
}
void depiler(list *p){
    if(*p == NULL) return;
    list tmp = (*p) -> suivant;
    free(*p);
    *p = tmp;
}
void Affiche(list * p){
    list tmp = cree();
    int x;
    while(*p != NULL){
        x = tete(p);
        depiler(p);
        empiler(&tmp,x);
        printf("%d ",x);
    }
    while(tmp != NULL){
        x = tete(&tmp);
        empiler(p,x);
        depiler(&tmp);
    }
    printf("\n");
}
void decompose(list * p1,list * p2,list * f){
    int x;
    while(*p1 != NULL){
        x = tete(p1);
        empiler(p2,x);
        depiler(p1);
    }
    
    while(*p2 != NULL){
        x = tete(p2);
        if(x % 2 == 1) empiler(p1,x);
        else enfiler(f,x);
        depiler(p2);
    }
    Affiche(f);
    
    while(*f != NULL){
        x = tete(f);
        empiler(p2,x);
        defiler(f);
    }
    
}
#define TAILLE 10
#define MAX 10

int main(){
    srand(time(NULL));
    list p1 = cree() ,p2 = cree(),f = cree();
    int i; 
    for(i = 0; i < TAILLE; i++) empiler(&p1,rand() % MAX);
    printf("Cest P1 avant: ");
    Affiche(&p1);
    
    decompose(&p1,&p2,&f);
    printf("Cest P1 apres: ");
    Affiche(&p1);
    
    printf("Cest P2: ");
    Affiche(&p2);



}