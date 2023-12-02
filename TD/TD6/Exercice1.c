#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TailleChaine 19


typedef struct Date{
    int Jour;
    int Mois;
    int Anne;
}Date;

typedef struct employee{
    char Nom[TailleChaine];
    char Prenom[TailleChaine];
    char Ville[TailleChaine];
    char Rue[TailleChaine];
    int CodePostale;
    int Telephone;
    Date D;
} employee;


employee lireFiche(){
    employee P1;
    printf("Donner Votre Nom: ");
    scanf("%s",&(P1.Nom));
    fflush(stdin);
    printf("Donner Votre Prenom: ");
    scanf("%s",&(P1.Prenom));
    fflush(stdin);
    printf("Donner Votre Ville: ");
    scanf("%s",&(P1.Ville));
    fflush(stdin);
    printf("Donner Votre Rue: ");
    scanf("%s",&(P1.Rue));
    fflush(stdin);
    printf("Donner Votre CodePostale: ");
    scanf("%d",&(P1.CodePostale));
    fflush(stdin);
    printf("Donner Votre Telephone: ");
    scanf("%d",&(P1.Telephone));
    fflush(stdin);
    printf("Donner Votre Jour de Naissance: ");
    scanf("%d",&(P1.D.Jour));
    fflush(stdin);
    printf("Donner Votre Mois de Naissance: ");
    scanf("%d",&(P1.D.Mois));
    fflush(stdin);
    printf("Donner Votre Annee de Naissance: ");
    scanf("%d",&(P1.D.Anne));
    fflush(stdin);
    return P1;
}
void afficheFiche(employee * DATA){
    int i, N = sizeof(DATA) / sizeof(employee);
    for(i = 0; i < N; i++){
        printf("Personne d'ID: %d '%s %s'\n",i,DATA[i].Nom,DATA[i].Prenom);
        printf("\t Ville: %s",DATA[i].Ville);
        printf("\t Rue: %s",DATA[i].Rue);
        printf("\t CodePostale:%s",DATA[i].CodePostale);
        printf("\t Telephone: +216%d",DATA[i].Telephone);
        printf("\t Date de Naissance: %d/%d/%d",DATA[i].D.Jour,DATA[i].D.Mois,DATA[i].D.Anne);
        printf("\n");
    }
    return;
}
employee * remplirTab(){
    int i = 0 , N;
    do{
        printf("Donner Le Nombre des Employees: ");
        scanf("%d",&N);
    }while(N < 1);
    employee * DATA = (employee *) malloc(sizeof(employee) * N);

    for(i = 0; i < N ; i++){
        printf("\nEmployee N%d:\n",i);
        DATA[i] = lireFiche();
    }

    return DATA;
}


int rechNom(char * S, employee * DATA){
    int i = 0,  N = sizeof(DATA) / sizeof(DATA[0]);
    while(i < N && strcmp(DATA[i].Nom,S) != 0) i++;
    if(i == N) return -1;
    else return i;
}


int rechTel(int Tel, employee * DATA){
    int i = 0,  N = sizeof(DATA) / sizeof(DATA[0]);
    while(i < N && DATA[i].Telephone != Tel) i++;
    if(i == N) return -1;
    else return i;
}
int main(){
    
    employee * DATA = remplirTab();
    
    afficheFiche(DATA);

    return 0;
}
