/*
#include <stdio.h>
int Convertir(int N,int b,int i){
    if(N / b == 0) return N * i;
    return  (N % b) * i + Convertir(N / b , b , i * 10);
}

int main(){
    int i = 1; 
    int N; 
    int b;
    printf("Donner Le Nombre decimal a Convertir: ");
    scanf("%d",&N);
    printf("Donner la Base: ");
    scanf("%d",&b);
    printf("Le Nombre Convertie est %d\n",Convertir(N,b,i));
    return 0;
}
*/

// Integer Method :

/*

#include <stdio.h>

long long int Convertir(int n ,int b){
    if (n / b == 0) return n;
    return n % b + Convertir(n / b , b) * 10;
}

int main(){
    int n;
    int b; 
    printf("Donner n: ");
    scanf("%d",&n);
    printf("Donner La Base: ");
    scanf("%d",&b);

    printf("%d en  la base %d  ==>  %d\n",n,b,Convertir(n,b));

    return 0;
}

*/

// AFFICHAGE Method : 
#include <stdio.h>

void Converted(int n, int b){
    if(n / b == 0) {
        printf("%d",n);
        return;
    }
    Converted(n / b ,b);
    printf("%d",n % b);
 
}

int main(){
    int n , b; 
    printf("Donner n: ");
    scanf("%d",&n);
    printf("Donner b: ");
    scanf("%d",&b);
    printf("Le Nombre Converti %d = ",n);
    Converted(n,b);
    return 0;
}
