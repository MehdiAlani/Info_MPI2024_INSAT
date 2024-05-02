#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NB 100
#define TAILLE 10


// Premiere Partie

typedef struct noued {
    int valeur;
    struct noued * suivant;
}noued;

typedef noued * pile; 

pile Cree(){
    return NULL;
}

int Test(pile p) {
    return p == NULL;
}

pile empiler(pile p,int val) {
    pile l = (pile)malloc(sizeof(noued));
    l -> valeur = val;
    l -> suivant = NULL;
    if(p == NULL) return l;
    pile move = p;
    while (move -> suivant != NULL) move = move -> suivant; 
    move -> suivant = l;
    return p;
}
pile depiler(pile p){
    if (p == NULL) return NULL;
    if (p -> suivant == NULL) {
        free(p);
        return NULL;
    }
    pile move = p;
    while (move ->  suivant -> suivant != NULL) move = move -> suivant;
    free(move-> suivant);
    move -> suivant = NULL;
    return p;
}
pile tete(pile p){
    pile move = p;
    while(move -> suivant != NULL) move = move -> suivant;
    return move;
}
int leng(pile p){
    if (p == NULL) return 0;
    pile move = p;
    int i  = 1 ;
    while (move -> suivant != NULL) {
        move = move -> suivant;
        i++;
    }
    return i;
}
void Affiche(pile p){
    if(p == NULL) return;
    if(p -> suivant == NULL) printf("%d\n" , p -> valeur);
    Affiche(p -> suivant);
    printf("%d\n",p -> valeur);
}


// 2eme Partie 

void decompose(pile p1 ,pile * p2 ,pile * p3){
    pile move = p1;
    while(move != NULL){
        if((move -> valeur) % 2) *p3 = empiler(*p3,move -> valeur);
        else *p2 = empiler(*p2,move-> valeur);
        move = move -> suivant;
    }
}
pile fusion(pile p1,pile p2,pile p3){
    pile move1 = p1 , move2 = p2;
    while(move1 !=  NULL && move2 != NULL){
        if(move1 -> valeur > move2 -> valeur) {
            p3 = empiler(p3,move1 -> valeur);
            move1 = move1 -> suivant;
        }
        else {
             p3 = empiler( p3,move2 -> valeur);
            move2 = move2 -> suivant;
        }
    }
    if(move1 == NULL) move1 = move2;
    while(move1 != NULL){
        p3 = empiler(p3,move1 -> valeur);
        move1 = move1 -> suivant;
    }  
    return p3;
}

int main(){
    // 1 
    pile p2,p3 = Cree();
    pile p1 = Cree();
    srand(time(NULL));
    int random_nb = rand() % MAX_NB ,i;



    for(i = 1; i <= TAILLE ; i++){
        p1 = empiler(p1,random_nb);
        random_nb = rand() % MAX_NB;
    }
    Affiche(p1);
    printf("\n");
    p1= depiler(p1);
    Affiche(p1);

    // 2 

    p3 = p2 = NULL;
    decompose(p1,&p2,&p3);
    printf("This p2: \n");
    Affiche(p2);
    printf("This p3: \n");
    Affiche(p3);


    // 3
    printf("\nQ3: \n");
    while(p1 != NULL) p1 = depiler(p1);
    while(p2 != NULL) p2 = depiler(p2);
    while(p3 != NULL) p3 = depiler(p3);


    random_nb = rand() % MAX_NB;
    p1 = empiler(p1,20);
    p2 = empiler(p2,30);
    p1 = empiler(p1,16);
    p2 = empiler(p2,14);
    p1 = empiler(p1,14);
    p2 = empiler(p2,10);
    p1 = empiler(p1,4);
    p2 = empiler(p2,6);
    p2 = empiler(p2,2);

    printf("This p1: \n");
    Affiche(p1);
    printf("This p2: \n");
    Affiche(p2);

    p3 = fusion(p1,p2,p3);
    printf("Voici p3: \n");
    Affiche(p3);
    return 0;
}   
