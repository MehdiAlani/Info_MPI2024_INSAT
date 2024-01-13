#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TailleChaine 30
#define Number 10
#define ARABIC_NAMES { "Aisha", "Omar", "Leila", "Musa", "Hana", "Youssef", "Lina", "Zayd", "Sara", "Khalid" }

typedef struct Client{
    char Nom[TailleChaine];
    int Code;
    float solde;
}Client;
float Recherche_dicotomique(int nb,Client * DATA){
    int bsup = DATA[Number-1].Code , binf = DATA[0].Code; 
    int i = (binf + bsup) / 2;
    if (nb == bsup) return DATA[Number-1].solde;
    else if (nb == binf) return DATA[0].solde;
    while(i != nb){
        if(i < nb) binf = i; 
        else bsup = i;
        i = (binf + bsup) / 2; 
    }
    i = i - DATA[0].Code;
    return DATA[i].solde;
}



int main() {
    srand(time(0));
    int i , randnb = rand() % 3000,Code;
    float randf ; 
    char const * Noms[Number] = ARABIC_NAMES;
    Client DATA[Number];


    for(i = 0; i < Number; i++,randnb++){
        randf = ((float) rand() / randnb); 
        strcpy(DATA[i].Nom,Noms[i]); 
        DATA[i].Code = randnb;
        DATA[i].solde = randf;
        printf("Nom: '%s' Code: %d , solde:%0.2f\n",DATA[i].Nom,DATA[i].Code,DATA[i].solde);
    }
    do{
        printf("Donner Un Code dun Client: ");
        scanf("%d",&Code);
    }
    while(Code < DATA[0].Code || Code > DATA[Number-1].Code);

    printf("%0.2f\n",Recherche_dicotomique(Code,DATA));

}
  
