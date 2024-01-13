#include <stdio.h>

int EstCroissant(int nb){
    while (nb>=10) {
        if(nb % 10 < (nb / 10) % 10){
            return 0;
        }
        nb = nb / 10;
    }
    return 1;
}

int main(){
    int N;
    do{
        printf("Donner un Nombre: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<0);
    if(EstCroissant(N)==1) printf("C'est une progression croissante\n");
    else printf("Ce n'est pas une progression croissante\n");
    return 0;
}