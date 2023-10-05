#include <stdio.h>
#include <math.h>

int main(){
    float a , b , c  , delta;
    printf("\nDonner a: ");
    scanf("%f",&a);
    printf("\nDonner b: ");
    scanf("%f",&b);
    printf("\nDonner c: ");
    scanf("%f",&c);
    if(a==0 && b==0 && c==0) printf("C'est une infinite Des solutions");
    else if (a== 0 && b==0) printf("Pas de Solutions");
    else if (b==0 && c==0) printf("0 est la seul Solution");
    else if (a==0) printf("%0.2f est la seul Solution",-c/b);
    else if(a+b+c == 0) printf("1 et %0.2f sont les Solutions",c/a);
    else if(a-b+c == 0) printf("-1 et %0.2f sont les Solutions",-c/a);
    else{
        delta = pow(b,2) - 4 * a * c;
        if(delta < 0) printf("Pas de Solutions");
        else if(delta == 0) printf(" %0.2f est la Solution",-b/(2*a));
        else printf("%0.2f et %0.2f sont les Solutions",(-b+sqrt(delta))/(2*a),(-b-sqrt(delta))/(2*a));
    } 
    return 0;
}