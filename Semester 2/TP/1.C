#include <stdio.h>
#include <stdlib.h>

typedef struct cellule{
    int val;
    struct cellule * suivant;
}cellule;

typedef cellule * list;

list ajout_fin(list L,int val){
    list c = (list) malloc(sizeof(cellule));
    c -> suivant = NULL;
    c -> val = val;
    if(L == NULL) return c;

    list move = L;
    while(move -> suivant != NULL){
        move = move -> suivant;
    }
    move -> suivant = c;
    return L;
}
void init_sous(list L,list * LS_paire,list * LS_impaire){
    list move = L;
    while(move != NULL){
        if(move -> val % 2) *LS_impaire = ajout_fin(*LS_impaire,move -> val);
        else *LS_paire = ajout_fin(*LS_paire,move -> val);
        move = move -> suivant;
    }
}
void Affiche(list L){
    list move = L;
    printf("\n");
    while(move != NULL){
        printf("%d ",move -> val);
        move = move -> suivant;
    }
    printf("\n");
}
int main(){
    list L = NULL;
    list LS_paire = NULL, LS_impaire = NULL;
    L = ajout_fin(L,3);
    L = ajout_fin(L,2);
    L = ajout_fin(L,1);
    L = ajout_fin(L,6);

    init_sous(L,&LS_paire,&LS_impaire);
    printf("Cest L:\n");
    Affiche(L);
    printf("Cest LS_impaire:\n");
    Affiche(LS_impaire);
    printf("Cest LS_paire:\n");
    Affiche(LS_paire);
    
}