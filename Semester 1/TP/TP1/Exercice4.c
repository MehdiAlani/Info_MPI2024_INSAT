#include <stdio.h>
int main(){
    int U1=1,U2=1,N,aux;
    do{
        printf("Donner le Nombre N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<0);

    for(int i =0 ; i < N;i++){
        aux = U2;
        U2 = U1 + U2;
        U1 = aux;
    }
    printf("le %dieme Terme de cette Suite U(%d) = %d",N,N,U1);

    return 0;
}