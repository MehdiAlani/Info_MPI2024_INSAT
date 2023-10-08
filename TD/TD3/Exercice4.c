#include <stdio.h>
int Amis(int N1 , int N2){
    int S1 = 0 , S2 = 0;
    for(int i=2 ;i <= N1/2; i++){
        if(N1 % i == 0) S1 = S1 + i;
    }
    for(int i=2 ;i <= N2/2; i++){
        if(N2 % i == 0) S2 = S2 + i;
    }
    return (S1==N2 && S2 == N1);
}

int main(){
    int N, M;
    do{
        printf("Donner M: ");
        scanf("%d",&M);
        printf("Donner N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N < 1 || M < 1);
    
    if(Amis(M,N)) printf("Le deux nombres sont amis :)");
    else printf("Le deux nombres ne sont pas amis :(");
    return 0;
}