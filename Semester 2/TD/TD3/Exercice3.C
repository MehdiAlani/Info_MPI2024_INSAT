#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct el{
    int val;
    struct el  * suivant;
}el;

typedef el * file;

file cree(){
    return NULL;
}
int tete(file * f){
    if(*f != NULL) return (*f) -> val;
}
void enfiler(file * f,int val){
    file aux = (file) malloc(sizeof(el));
    aux -> val = val;
    aux -> suivant = NULL;
    if(*f == NULL) {
        *f = aux;
        return;
    } 
    file move = *f;
    while(move -> suivant != NULL){
        move = move -> suivant;
    }
    move -> suivant = aux;
}
void defiler(file * f){
    if(*f == NULL) return;
    file tmp = cree();
    tmp = (*f) -> suivant;
    free(*f);
    *f = tmp;
}
void Affiche(file * f){
    int x;
    file tmp = cree();
    while(*f != NULL){
        x = tete(f);
        enfiler(&tmp ,x);
        printf("%d ",x);
        defiler(f);
    }
    while(tmp != NULL){
        x = tete(&tmp);
        enfiler(f,x);
        defiler(&tmp);
    }
    printf("\n");
}
void deplacer(file * f1,file * f2,file * f3){
    int x;
    while(*f1  != NULL){
        x = tete(f1);
        if(x % 2 == 1) enfiler(f2,x);
        else enfiler(f3,x);
        defiler(f1);
    }
    while(*f3  != NULL){
        x = tete(f3);
        enfiler(f2,x);
        defiler(f3);
    }
}
void inverser_file(file * f){
    if(*f == NULL) return;
    int x = tete(f);
    defiler(f);
    inverser_file(f);
    enfiler(f,x);
}
void copier(file * f1,file * f2,file * f3){
    int x;
    while(*f1 != NULL){
        x = tete(f1);
        enfiler(f3,x);
        if(x % 2 == 0) enfiler(f2,x);
        defiler(f1);
    }
    while(*f3 != NULL){
        x = tete(f3);
        defiler(f3);
        enfiler(f1,x);
    }
    inverser_file(f2);
}

#define TAILLE 10
#define MAX 10

int main(){
    file f1 = cree();
    file f2 = cree();
    file f3 = cree();
    srand(time(NULL));
    int i;
    /*
    printf("Cest 1\n");
    deplacer(&f1,&f2,&f3);
    for(i = 0; i < TAILLE; i++) enfiler(&f1,rand() % MAX);
    printf("Cest F1: ");
    Affiche(&f1);
    deplacer(&f1,&f2,&f3); 
    printf("Cest F2: ");
    Affiche(&f2);
    */
    printf("Cest 2\n");
    for(i = 0; i < TAILLE; i++) enfiler(&f1,rand() % MAX);
    copier(&f1,&f2,&f3);
    printf("Cest F1: ");
    Affiche(&f1);
    printf("Cest F2: ");
    Affiche(&f2);


}