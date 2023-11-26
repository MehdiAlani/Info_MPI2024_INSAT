#include <stdio.h>

int main(){
    int N;
     do{
        printf("Donner le Nombre de Lignes N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<1);
    for(int i =0;i<N;i++){
        for(int j = 0;j<N-i;j++) printf(" ");
        for(int j = 0;j<i*2+1;j++) printf("*");
        printf("\n");
    }
    return 0;
}