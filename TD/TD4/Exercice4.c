#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Partie 1 :


void Recherche(int * Tab , int b_inf, int b_sup ,int * min ,int * max){
    * min = 0; * max = 0;

    for(int i = b_inf ; i < b_sup ; i++){
        if(*(Tab + i) > *(Tab + *max)) *max = i;
        if(*(Tab + i) < *(Tab + *min)) *min = i;
    }
    return;
}


// Partie 2 :

void Permuter(int * A , int * B){
    *A = *A + *B;
    *B = *A - *B;
    *A = *A - *B;
    return;
}

// Partie 3 : 

void TriMinMax(int * Tab , int n){
    int min,max;
    
    for(int i = 0; i < n / 2; i++){
        Recherche(Tab,i,n-i,&min,&max);
        Permuter(Tab + i,Tab + min);
        Permuter(Tab +  n - 1 - i,Tab + max);
    }
    return;
}

#define MaxSize 10
#define MaxNumber 50

int main(){

    int min ,max;
    int T[2] = {2, 4};
    Recherche(T,1,2,&min,&max);
    printf("Min = %d \\ Max= %d\n",min,max);
    
    
    srand(time(0));
    int Size = rand() % MaxSize + 2;
    int Tab[10];
    printf("\nTab non Trie : { ");
    for(int i = 0; i < Size ; i++){
        Tab[i] = rand() % MaxNumber ;
        printf("%d ",Tab[i]);
    }

    TriMinMax(Tab,Size);
    printf("}\nTab Triee:");
    for(int i = 0; i < Size ; i++){
        printf("%d ",Tab[i]);   
    }

    printf("\n");
    return 0;
}