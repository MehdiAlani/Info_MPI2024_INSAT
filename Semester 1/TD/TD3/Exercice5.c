#include <stdio.h>
int Mycielski(int N){
    int C=1 , M=2;
    for(int i = 1; i < N; i++){
        C = 3 * C + M;
        M = 2 * M + 1;
    }
    return C;
}

int main(){
    int N;
    do{
        printf("Donner le nieme Terme a Calculer: ");
        scanf("%d",&N);
        printf("\n");
    }while(N < 1);
    printf("C(%d)=%d",N,Mycielski(N));
    return 0;
}