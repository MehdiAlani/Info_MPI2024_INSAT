#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct el{
    int val;
    struct el * suivant;
}el;

typedef el * pile; 

int est_vide(pile * p){
    return(*p == NULL);
}
pile cree(pile * p){
    *p = NULL;
}
int tete(pile * p){
    if(*p != NULL) return (*p) -> val;
}
void empiler(pile * p,int val){
    pile aux = (pile) malloc(sizeof(el));
    aux -> val = val;
    aux -> suivant = *p;
    *p = aux;
}
void depiler(pile * p){
    if(*p == NULL) return ;
    pile aux = (*p) -> suivant;
    free(*p);
    *p = aux;
}
void affiche(pile * p){
    pile tmp;
    cree(&tmp);
    int x;
    while(est_vide(p) != 1){
        x = tete(p);
        depiler(p);
        empiler(&tmp,x);
        printf("%d ",x);
    }
    while(est_vide(&tmp) != 1){
        x = tete(&tmp);
        empiler(p,x);
        depiler(&tmp);
    }
    printf("\n");
}
void deplacer(pile *p1 ,pile *p2, pile * p3){
    int x;
    while(est_vide(p1) != 1){
        x = tete(p1);
        if(x % 2 == 0) empiler(p2,x);
        else empiler(p3, x);
        depiler(p1);
    }
    while(est_vide(p3) != 1){
        x = tete(p3);
        empiler(p2,x);
        depiler(p3);
    }
}
void copier(pile *p1,pile *p2,pile *p3){
    int x;
    while(est_vide(p1) != 1){
        x = tete(p1);
        depiler(p1);
        empiler(p3,x);
    }
    while(est_vide(p3) != 1){
        x = tete(p3);
        depiler(p3);
        if(x % 2 == 0) empiler(p2,x);
        empiler(p1,x);
    }
}
#define TAILLE_PILE 10
#define MAX 10

int main(){
    pile p1 , p2 , p3;
    cree(&p1);cree(&p2);cree(&p3);
    int i;
    srand(time(NULL));
    for(i = 0; i < TAILLE_PILE; i++) empiler(&p1 , rand() % MAX);
    printf("Cest 1: \n");
    printf("Cest p1: ");
    affiche(&p1);
    deplacer(&p1,&p2,&p3);
    printf("Cest p2: ");
    affiche(&p2);
    while(est_vide(&p2) != 1) depiler(&p2);

    for(i = 0; i < TAILLE_PILE; i++) empiler(&p1 , rand() % MAX);
    printf("Cest 2: \n");
    copier(&p1,&p2,&p3);
    printf("Cest p1: ");
    affiche(&p1);
    printf("Cest p2: ");
    affiche(&p2);
}   
