#include <stdio.h>
#include <stdlib.h>


typedef struct noued{
    float moy;
    struct noued * suivant;
    struct noued * prec; 
}noued;

typedef noued * list;

list Ajout_tete(list L,float val){
    list t = (list) malloc(sizeof(noued));
    t -> suivant = L;
    t -> prec = NULL;
    t -> moy = val;
    if(L == NULL) return t;
    L -> prec = t;
    return t;
}

void Affiche(list L){
    list move = L;
    printf("\n");
    while(move != NULL){
        printf("%f ",move -> moy);
        move = move -> suivant;
    }
    printf("\n");
}

list Supprimer(list L){
    if (L == NULL) return L;
    list move = L -> suivant;
    move -> prec = NULL;
    free(L);
    return move;
}
int Somme(list L){
    list move = L;
    float S = 0;
    while(move != NULL){
        S = S + move -> moy;
        move = move -> suivant;
    }
    return S;
}

void Affiche_2(list L){
    if (L == NULL) return;
    list move = L;
    while(move != NULL){
        if(move -> moy > 13){
            printf("%f ",move -> moy);
        }
        move = move -> suivant;
    }
    printf("\n");
    return;
}
void Chercher(list L){
    float moy;
    printf("Donner un moy:");
    scanf("%f",&moy);
    list move = L;
    int num = 1;
    while (move != NULL && moy != move -> moy ){
        move = move -> suivant;
        num++;
    }
    if(move == NULL) printf("Pas de moyenne\n");
    else printf("Premiere moyenne trouve numero %d",num);
}
int main(){
    list L = NULL;
    L = Ajout_tete(L,12.5);
    L = Ajout_tete(L,2.5);
    L = Ajout_tete(L,15.5);
    Affiche(L);
    L = Supprimer(L);
    Affiche(L);

    int S = Somme(L);
    printf("La Somme est %d\n",Somme(L));


    // Autre Structure 
    list L2 = NULL;
    L2 = Ajout_tete(L2,14);
    L2 = Ajout_tete(L2,15);
    L2 = Ajout_tete(L2,12);
    L2 = Ajout_tete(L2,19);
    L2 = Ajout_tete(L2,11);
    printf("Les moy sup a 13 sont :\n");
    Affiche_2(L2);
    Chercher(L2);
}
