#include <stdio.h>

int main(){
    int N , nbTemp ,Somme=0 , Produit=1 ;
    float Moyenne;
    do{
        printf("Donner le Nombre N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<1);
    for(int i = 1 ;i <= N;i++){
        printf("Donner le nombre numero %d: ",i);
        scanf(" %d",&nbTemp);
        printf("\n");
        Somme = Somme + nbTemp;
        Produit = Produit * nbTemp;
    }
    Moyenne= (float)Somme / N;
    printf("La Somme des %d Nombres (S = %d) de Produit (P = %d) et de Moyenne (M = %0.2f)",N,Somme,Produit,Moyenne);
}