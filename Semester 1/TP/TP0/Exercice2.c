#include <stdio.h>


int main(){
    int a,b;

    printf("Donner le nombre a: ");
    scanf("%d",&a);
    printf("\nDonner le nombre b: ");
    scanf("%d",&b);

    
    printf("\nLe quotien de cette division est %d et de reste %d",a/b,a%b);
    return 0;
}