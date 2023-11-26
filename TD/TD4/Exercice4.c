#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Recherche(int * Tab , int b_inf, int b_sup ,int * min ,int * max){
    * min = b_inf; * max = b_sup;

    for(int i = b_inf ; i < b_sup ; i++){
        if(Tab[i] >  Tab[*max]) *max = i;
        else if(Tab[i] <  Tab[*min]) * min = i;
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
        printf("min = %d , max = %d => %d\n",min,max,i);
        Permuter(Tab + i,Tab + min);
        Recherche(Tab,i,n-i,&min,&max);
        printf("min = %d , max = %d  => %d \n",min,max,i);
        Permuter(Tab +  n -1 - i,Tab + max);
    }
    return;
}

#define MaxSize 12
#define MaxNumber 50

int main(){
    int min ,max;
    srand(time(0));
    int Sizef = 4;
    int Tab[] = {4,5,2,1};

    TriMinMax(Tab,Sizef);
    printf("}\nTab Triee:");

    for(int i = 0; i < Sizef; i++) printf("%d ",Tab[i]);   
    printf("\n");
    return 0;
    
}