#include <stdio.h>
#include <math.h>

int main(){
    float XA,YA,XB,YB;
    double DIST;
    printf("Donner XA: ");
    scanf("%f",&XA);
    printf("\nDonner XB: ");
    scanf("%f",&XB);
    printf("\nDonner YA: ");
    scanf("%f",&YA);
    printf("\nDonner YB: ");
    scanf("%f",&YB);

    DIST=sqrt(pow((XB-XA),2)+pow((YB-YA),2));
    printf("\nLa Distance entre A et B => %0.2f",DIST);
    return 0;
}