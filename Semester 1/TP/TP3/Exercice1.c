#include <stdio.h>
#include <stdlib.h>


int main(){
    int X,n;
    int  * p , * k;
    int i;
    printf("Donner X: ");
    scanf("%d",&X);
    do{
        printf("Donner le Taille de Tableau : ");
        scanf("%d",&n);
    }while(n < 1);
    int * A = (int * ) malloc(n * sizeof(int));
    i = 0;
    for( p = A ; p <  A + n ; p++){
        printf("Donner A[%d]: ",i);
        scanf("%d",p);
        i++;
    }
    for(p = A; p < A + n; p++){
        if(*p == X){
            for(k = p + 1 ; k < A + n; k++){
                *(k - 1) = *k; 
            }
            n--;
            realloc(A , n * sizeof(int));
        }
    }
    for(p = A ; p < A + n;p++) printf("%d ",*p);
    return 0;
}