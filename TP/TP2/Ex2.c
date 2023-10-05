#include <stdio.h>
int main(){
    int T[50];
    int N;
    do{
        printf("Donner La taille du tableau comprise entre 1 et 50: ");
        scanf("%d",&N);
    }while(N<1 || N>50);
    for (int i =0;i<N;i++){
        printf("\nDonner T[%d] = ",i);
        scanf("%d",&T[i]);
    }
    printf("T = {");
    for (int i=0;i<N-1;i++) printf("%d,",T[i]);
    printf("%d}",T[N-1]);
    return 0;
}