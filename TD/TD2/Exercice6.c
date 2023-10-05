#include <stdio.h>

int main(){
    int F0 = 1;
    int F1 = 1;
    int N,aux;
    do{
        printf("Donner le nombre N: ");
        scanf("%d",&N); 
        printf("\n");
    }while(N < 0);
    printf("Les %d premiers termes de cette Suite sont { %d , %d ",N,F0,F1);
    for(int i = 3; i <= N ;i++){
        aux = F1;
        F1 += F0;
        F0 = aux;
        printf(", %d ",F1);
    }
    printf("}\n");
    return 0;
}