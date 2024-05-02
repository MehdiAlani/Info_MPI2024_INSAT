#include <stdio.h>
#include <math.h>
#define MAX_NB 99999

int nb_div(int n){
    int nb_divs = 2;
    for(int i = 2; i < sqrt(n); i++){
        if(n % i == 0) nb_divs++;
    }
    return nb_divs;
}

int main(){
    int i , j;
    int Max_nb = 0;
    int nb_divs;
    for(i = 1; i < MAX_NB; i++){
        printf("%d : ",i);
        nb_divs =  nb_div(i);
        if(nb_div(i) > nb_div(Max_nb)) Max_nb = i;
        for(j = 0;j < nb_divs;j++){
            printf("# ");
        }
        printf("\n");
    }
    printf("Max is = %d has %d divs \n",Max_nb,nb_div(Max_nb));
}
