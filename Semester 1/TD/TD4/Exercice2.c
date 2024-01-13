#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE_TAB 15
int main(){
    int nb = 0;
    srand(time(0));
    int Tab[SIZE_TAB];
    for (int i = 0; i < SIZE_TAB; i++){
        Tab[i] = rand() % 100;
        printf("%d ",Tab[i]);
    } 
    printf("\n");
    int max = 0, j = 0, digit = Tab[0], count = 0;

    for(int i = 1; i < SIZE_TAB; i++){
        if( Tab[i] >= digit){
            count++;
        }
        else{
            if(max < count) {
                max = count;
                j = i - 1;
            }
            count = 0;
        }
        digit = Tab[i];
    } 

    for(int i = j-max; i <= j;i++){
        printf("%d ",Tab[i]);
    }
    printf("\n");
    return 0;
}