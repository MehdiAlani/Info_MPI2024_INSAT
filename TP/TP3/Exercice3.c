#include <stdio.h>
#include <stdlib.h>

int main(){
    int * PA , * PB;
    int N , M,i=0;
    do{
        printf("Donner M: ");
        scanf("%d",&M);
        printf("Donner N: ");
        scanf("%d",&N);
    }while(M < 0 && N < 0);
    
    int * A = (int *) malloc(sizeof(int) * N);
    int * B = (int *) malloc(sizeof(int) * M); 
    for(PA = A ; PA < A + N ; PA++){
        printf("Donner A[%d]=",i);
        scanf("%d",PA);
        i++;
    }
    i=0;
    for(PB = B ; PB < B + M ; PB++){
        printf("Donner B[%d]=",i);
        scanf("%d",PB);
        i++;
    }

    A = (int * ) realloc(A, (N + M) * sizeof(int));
    for(PA = A; PA < A + N ; PA++) printf("%d ",*PA);
    for(PA = A + N,PB = B; PA < A + N + M ; PA++,PB++){
        *PA = *PB;
        printf("%d ",*PA);
    }
    printf("\n");
    return 0;
}