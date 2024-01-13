#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;
    short int Trie = 0;
    srand(time(0));
    
    do{
        printf("Donner la taille de Tableau: ");
        scanf("%d",&n);
    }while(n < 1);
    
    int * T = (int *) malloc(sizeof(int) * n);
    for(int * i = T; i < T + n; i++) {
        *i = rand() % 10;
        printf("%d ",*i); 
    }
    while(!Trie){
        Trie = 1;
        for(int * i = T ; i < T + n - 1 ; i++){
            if( *i  > *(i + 1) ){
                Trie = 0;
                *i = *i + *(i+1);
                *(i+1) = *i - *(i+1);
                *i = *i - *(i+1);
            }
        }
    }
    printf("\n");
    for(int * i = T; i < T + n; i++) printf("%d ",*i); 
    return 0;
}