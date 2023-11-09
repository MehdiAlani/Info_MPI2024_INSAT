#include <stdio.h>


int main(){
    int nb, c;
    printf("Donner un entier: ");
    scanf("%d",&nb);
    fflush(stdin);
    printf("Donner Votre Operation : ");
    scanf("%c",&c);
    switch(c){
        case '+':
            printf("%d",nb+2);
            break;
        case '-':
            printf("%d",nb-2);
            break;
        case '/':
            printf("%d",nb/2);
            break;
        case '*':
            printf("%d",nb*2);
            break;
        default:
            printf("Operation pas supportee\n");
    }
    return 0;
}
