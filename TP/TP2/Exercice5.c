#include <stdio.h>


int main(){
    int N,Somme=0;
    do{
        printf("Donner le Nombre N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<1);
    while(N != 0){
        Somme = Somme + N % 10; 
        N = N / 10;
    }
    printf("La Somme des chiffres de %d est (S = %d)",N,Somme);
    return 0;
}