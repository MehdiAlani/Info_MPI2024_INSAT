#include <stdio.h>

int main(){
    char c;
    printf("Donner un caractere: ");
    scanf("%c",&c);
    printf("\nLe code ASCII de ce caractere est %d",(int)c);
    return 0;
}