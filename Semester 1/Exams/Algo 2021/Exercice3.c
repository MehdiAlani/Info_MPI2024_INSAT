#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 1.Declaration:

typedef struct Personne{
    int Cin;
    char Nom[20];
    char Prenom[20];
    int Age;
}Personne;
typedef struct Test_Covid{
    Personne * Elt;
    int Result_test;
}
    
int main(){



    return 0;
}