// Premiere Methode: 
/*

#include <stdio.h>

int Somme(int n){
    if (n == 0) return 0;
    return n + Somme(n - 1);
}
int main(){
    int n;
    printf("Donner n:");
    scanf("%d",&n);
    printf("La Somme des %d Premiers nombres egale a %d \n",n,Somme(n));
}

*/ 

// Duxieme Methode : 


#include <stdio.h>

void Somme(int n , int * S){
    if(n == 0) *S = 0;
    else {
        Somme(n-1,S);
        *S = *S + n;
    }
}

int main(){
    int * S; 
    int n;
    printf("Donner n: ");
    scanf("%d",&n);
    Somme(n,S);
    printf("La Somme de %d => %d\n",n,*S);
    return 0;    
}