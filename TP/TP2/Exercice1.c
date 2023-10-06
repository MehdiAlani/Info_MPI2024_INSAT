#include <stdio.h>

int main(){
    int E;
    char Op;
    printf("Donner un entier: ");
    scanf("%d",&E);
    printf("\nDonner Une Operation: ");
    scanf(" %c",&Op);
    switch(Op){
        case '+':
            printf("le Resultat: %d",E+2);
            break;
        case '-':
            printf("le Resultat: %d",E-2);
            break;
        case '*':
            printf("le Resultat: %d",E*2);
            break;
        case '/':
            printf("le Resultat: %d",E/2);
            break;
        default:
            printf("Operation non Valide");
    }
    return 0;
}