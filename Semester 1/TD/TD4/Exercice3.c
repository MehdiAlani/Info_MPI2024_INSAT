#include <stdio.h>

#define SIZE 20


int main(){
    int Tab[SIZE];
    for (int i = 0; i < SIZE; i++) Tab[i] = i+1;
    int TabRes[SIZE];
    int j = 0;
    for(int i = SIZE / 2 + 1; i < SIZE ; i++){
        TabRes[j] = Tab[i];
        j++;
    }
    for(int i = 0 ; i <= SIZE / 2; i++){
        TabRes[j] = Tab[i];
        j++;
    }
    for(int i = 0 ; i < SIZE; i++) printf("%d ", Tab[i]);
    printf("\n");
    for(int i = 0 ; i < SIZE; i++) printf("%d ", TabRes[i]);
    return 0;
}