#include <stdio.h>


int main(){

    int A,B,C,aux;
    printf("Donner la valeur de A: ");
    scanf("%d",&A);
    printf("\nDonner la valeur de B: ");
    scanf("%d",&B);
    printf("\nDonner la valeur de C: ");
    scanf("%d",&C);
    aux=A;
    A=B;
    B=C;
    C=aux;
    printf("\nA:%d, B:%d , C:%d",A,B,C);
    return 0;
}