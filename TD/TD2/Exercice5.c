#include <stdio.h>
int main(){
    int Nb;
    short int Premier = 1;
    do{
    printf("Donner un nombre positif : ");
    scanf("%d",&Nb);
    printf("\n");
    }while(Nb<=0);
    for(int i = 2; i < Nb / 2; i++){
        if(Nb % i == 0){
            Premier = 0;
            break;
        }
    }
    if(Premier==1) printf("%d ,C'est un nomber Premier",Nb);
    else printf("%d, Ce n'est pas un nombre premier",Nb);
    return 0;
}