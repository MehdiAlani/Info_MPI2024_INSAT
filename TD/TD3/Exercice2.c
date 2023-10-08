#include <stdio.h>
void SommePaireProdImpaire(int nb,int *Somme,int *Produit){
    while(nb!=0){
        if(nb%10 % 2== 0){
            *Somme = *Somme + nb%10; 
        }
        else{
            *Produit = *Produit * (nb % 10);
        }
        nb = nb / 10;
    }
}
int main(){
    int N , Produit = 1, Somme =0;
    do{
        printf("Donner un Nombre: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<0);
    SommePaireProdImpaire(N,&Somme,&Produit);
    printf("La Somme S = %d et le Produit P=%d \n",Somme,Produit);
    return 0;
}