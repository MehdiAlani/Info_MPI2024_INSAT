#include <stdio.h>


int main(){
    char c1,c2;
    printf("Donner le premier caractere: ");
    scanf("%c",&c1);
    printf("\nDonner le deusieme caractere: ");
    scanf(" %c",&c2);
    printf("\nLe code ASCII du premier caractere est %d et de deusieme est %d",(int)c1,(int)c2);
    return 0;
}