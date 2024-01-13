#include <stdio.h>
#include <stdlib.h>
int main(){
    float a ,b;
    char Operation;
    printf("Donner le nombre a = ");
    scanf("%f",&a);
    printf("\nDonner le nombre b = ");
    scanf("%f",&b);
    printf("\nDonner Votre Operation : ");
    scanf(" %c",&Operation);
    printf("\n");
    switch(Operation){
        case '+':
            printf("%0.2f + %0.2f = %0.2f",a,b,a+b);
            break;
        case '-':
            printf("%0.2f - %0.2f = %0.2f",a,b,a-b);
            break;
        case '*':
            printf("%0.2f * %0.2f = %0.2f",a,b,a*b);
            break;
        case '/':
            if(b==0){
                printf("On ne peut pas deviser par 0");
                break;
            }
            printf("%0.2f / %0.2f = %0.2f",a,b,a/b);
            break;
        default:
            printf("%c, Ce n'est une Operation Valide");
    }
    return 0;
}