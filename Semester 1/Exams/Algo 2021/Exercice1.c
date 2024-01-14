// Algorithme points cols : 
/*

Algorithme Programme Principale:
Var:
    M : tableau[1..50,1..50] d'entiers
    i , j  ,k: entier
Debut
    Pour i de 1 a 50 faire
        Pour j de 1 a 50 faire
            k <- 1     
            Tant que(k <= 50 Et M[i][k] >= M[i][j] Et M[k][j] =< M[i][j]) faire
                k <- k + 1 
            FinTantque
            Si k = 50 alors
                Ecrire("M[",i,"][",j,"] =>",M[i][j],"\n")
            FinSi
        FinPour
    FinPour
Fin

*/

// Programme en C:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAILLE_MATRICE 3
#define NombreMaxi 10

int main(){
    // Generer Une Matrice M d'entiers arbitreres  
    int M[TAILLE_MATRICE][TAILLE_MATRICE];
    srand(time(NULL));
    int i , j;
    printf("La Matrice M consiste de :\n");
    for(i = 0; i < TAILLE_MATRICE; i++){
        for(j = 0; j < TAILLE_MATRICE; j++){
            M[i][j] = rand() % NombreMaxi;
            printf("%2d ",M[i][j]);
        }
        printf("\n");
    }
    // Recherche Des Points Cols:
    int k;
    printf("Les Points Cols sont : \n");
    for(i = 0; i < TAILLE_MATRICE; i++){
        for(j = 0; j < TAILLE_MATRICE; j++){
            k = 0;
            while(k < TAILLE_MATRICE && M[i][k] <= M[i][j] && M[k][j] >= M[i][j]) k++;
            if(k == TAILLE_MATRICE) printf("M[%d][%d]: %d\n",i,j,M[i][j]);
        }
    }
    return 0;
}