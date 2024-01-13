#include <stdio.h>
int main(){
      int N,SomDiv,nbParfait=0;
    do{
        printf("Donner le Nombre N: ");
        scanf("%d",&N);
        printf("\n");
    }while(N < 1);
    for(int i =2; i<=N;i++){
        SomDiv=0;
        for(int j =1; j<i; j++){
            if(i%j==0) SomDiv=SomDiv+j;
        }
        if(SomDiv == i) nbParfait++;
    }
    printf("On a %d Nombres parfaits inferieur a %d",nbParfait,N);
    return 0;
}


