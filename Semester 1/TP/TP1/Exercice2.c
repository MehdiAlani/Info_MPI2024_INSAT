#include <stdio.h>
int main(){
    int N, SomDiv=0;
    do{
        printf("Donner le Nombre N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N<2);
    for(int i=1;i<N;i++){
        if(N % i == 0) SomDiv = SomDiv + i;
    }
    if(SomDiv == N) printf("C'est un nombre parfait");
    else printf("Ce n'est pas un nombre parfait");
}