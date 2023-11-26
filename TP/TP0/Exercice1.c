#include <stdio.h>


int main(){
    int a;
    int b;
    float c;

    printf("Donner le nombre a: ");
    scanf("%d",&a);
    printf("\nDonner le nombre b: ");
    scanf("%d",&b);
    c = (float)a/b;

    printf("La valeur de a est: %d\n",a);
    printf("La valeur de b est: %d\n",b);
    printf("La valeur de c est: %f\n",c);
    return 0;
}