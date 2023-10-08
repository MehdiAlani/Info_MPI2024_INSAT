#include <stdio.h>
int Frere(int N1 , int N2){
    int aux = N2;
    short int Valide = 1;
    while(N1 != 0 && Valide){
        N2 = aux;
        Valide=0;
        while(N2 !=0 && !Valide){
            if(N1 % 10 == N2 % 10){
                Valide = 1;
            }
            N2 = N2 / 10;
        }
        N1 = N1 / 10;
    }
    aux = N1;
    while(N2 != 0 && Valide){
        N1 = aux;
        Valide=0;
        while(N1 !=0 && !Valide){
            if(N1 % 10 == N2 % 10){
                Valide = 1;
            }
            N1 = N1 / 10;
        }
        N2 = N2 / 10;
    }
    return Valide;
}

int main(){
    int N1 , N2;
    do{
        
        printf("Donner N1: ");
        scanf("%d",&N1);
        printf("Donner N2: ");
        scanf(" %d",&N2);

    }while(N1 < 1 || N2 < 1);
    if(Frere(N1 , N2)) printf("Ce sont deux nombres Freres\n");
    else printf("Ce n'est pas deux nombres Freres\n");
    return 0;
}