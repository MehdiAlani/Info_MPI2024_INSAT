#include <stdio.h>
#include <stdlib.h>

typedef struct Noeud{
    struct   Noeud *  right;
    struct   Noeud *  down;
    int valeur; 
}Noeud;
typedef struct Matrice {
    int nb_lignes;
    int nb_colonnes;
    Noeud * tete;
}Matrice;

int main(){

    



    return 0;
}