#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct noeud{
    int val;
    struct noeud * suivant;
}noeud;

typedef noeud * file;

file cree(){
    return NULL;
}
file tete(file f){
    return f; 
}
void enfiler(file * f,int n){
    file fp = (file) malloc(sizeof(noeud));
    fp -> val = n;
    fp -> suivant = NULL;
    if(*f == NULL){
        *f = fp;
        return; 
    }
    file move = *f;
    while(move -> suivant != NULL) move = move -> suivant ;
    move -> suivant = fp;
    return;
}
void defiler(file * f){
    if (*f == NULL) return;
    file fp = (*f) -> suivant;
    free(*f);
    *f = fp;
}
int len(file * f){
    int n = 0;
    if (*f == NULL) return n;
    file aux = cree();
    while (*f != NULL){
        enfiler(&aux,(*f) -> val);
        defiler(f);
        n++;
    } 
    while(aux != NULL){
        enfiler(f,aux -> val);
        defiler(&aux);
    }
    return n;
}
void Affiche(file *f){
    printf("\n");
    if(*f == NULL) return;
    file aux = cree();
    while(*f != NULL){
        printf("%d ",(*f) -> val);
        enfiler(&aux, (*f) -> val);
        defiler(f);
    }
    while(aux != NULL){
        enfiler(f, aux -> val);
        defiler(&aux);
    }
    printf("\n");
    return;
}

void decomposer(file * f1, file * f2 , file * f3){
    file aux = cree();
    *f2 = cree(), *f3 = cree();
    while(*f1 != NULL){
        if((*f1) -> val % 2) enfiler(f3,((*f1) -> val));
        else  enfiler(f2,((*f1) -> val));
        enfiler(&aux,((*f1) -> val));
        defiler(f1);
    } 
    while(aux != NULL){
        enfiler(f1,aux -> val);
        defiler(&aux);
    }
    return;
}

void inserer(file *f,int n){
    file aux = cree();
    while(*f != NULL && (*f) -> val < n){
        enfiler(&aux, (*f) -> val);
        defiler(f);
    }
    enfiler(&aux,n);
    while(*f != NULL){
        enfiler(&aux, (*f) -> val);
        defiler(f);
    }
    *f = aux;
    return;
}
#define MAX_SIZE 400
#define MAX_NB 20

int main(){
    /*
    file f1 = cree();
    srand(time(NULL));
    int i;
    for(i = 0; i < MAX_SIZE; i++) enfiler(&f1, rand() % MAX_NB);

    file f2 = cree(),f3 = cree();
    decomposer(&f1,&f2,&f3);
    printf("Cest f1");
    Affiche(&f1);
    printf("Cest f2");
    Affiche(&f2);
    printf("Cest f3");
    Affiche(&f3);
    */


    file f = cree();
    enfiler(&f,1);
    enfiler(&f,4);
    enfiler(&f,19);
    enfiler(&f,20);
    inserer(&f,21);
    Affiche(&f);
}