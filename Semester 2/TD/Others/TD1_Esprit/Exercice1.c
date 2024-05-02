#include <stdio.h>
float Suite_iterative(int n){
    float U = 2;
    int i = 2;
    for(i = 0; i < n; i++){
        U = (3  * U) / (U + 5); 
    }
    return U;
}

float Suite_Recursive(int n , float U){
    if(n == 0) return U;
    return (Suite_Recursive(n - 1, 3 * U / (U + 5)));
}

int main(){
    int n;
    float U = 2;
    printf("La Suite est U(n) = (3 / U(n-1)) / (U(n) + 5) avec U0 = 2\n");
    printf("Donner n: ");
    scanf("%d",&n);
    printf("le terme n dapres iterative : %d est : %f\n",n,Suite_iterative(n));
    printf("le terme n dapres Recursive : %d est : %f\n",n,Suite_Recursive(n,U));
    return 0;
}