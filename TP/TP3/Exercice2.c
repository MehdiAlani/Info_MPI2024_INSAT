#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int * P1 , * P2 , AIDE , n;
    srand(time(0));
    do{
        printf("Donner la Taille du Tableau : ");
        scanf("%d",&n);
    }while(n < 1);

    int * A = (int *) malloc(sizeof(int) * n);
    for(P1 = A; P1 < A + n; P1++) {
        *P1 = rand() % 10;
        printf("%d ",*P1);
    }
    printf("\n");
    for(P1 = A, P2 = A + n - 1; P1 < A + n / 2; P1++,P2--){
        AIDE = *P1;
        *P1 = *P2;
        *P2 = AIDE;
    }

    for(P1 = A; P1 < A + n; P1++) printf("%d ",*P1);
    return 0;
}