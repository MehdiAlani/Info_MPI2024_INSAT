#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BARCELONA_PLAYERS_COUNT 7
#define BARCELONA_PLAYERS { "Lionel Messi", "Gerard Piqué", "Casemiro" ,"Frenkie de Jong", "Antoine Griezmann", "Sergio Busquets" ,"Sergio Ramos" }
#define BAR_NA {"AB","EU","CH","AB","AB","CH","EU"}

#define REAL_MADRID_PLAYERS_COUNT 7
#define REAL_MADRID_PLAYERS { "Lionel Messi","Karim Benzema", "Sergio Ramos", "Luka Modric", "Eden Hazard", "Casemiro" , "Gerard Piqué"}
#define REAL_NA {"AB","CH","EU","AB","AB","CH","EU"}

typedef struct Sportif{
    int Numero;
    char Nom[30];
    char NA[3];
}Sportif;


Sportif * Rechercher(){


}


int main(){
    int i;
    const char * Real[REAL_MADRID_PLAYERS_COUNT] = REAL_MADRID_PLAYERS;
    const char * Real_NA[REAL_MADRID_PLAYERS_COUNT] = REAL_NA;
    const char * BAR[BARCELONA_PLAYERS_COUNT] = BARCELONA_PLAYERS;
    const char * Bar_NA[REAL_MADRID_PLAYERS_COUNT] = BAR_NA;

    Sportif T1[BARCELONA_PLAYERS_COUNT];
    Sportif T2[REAL_MADRID_PLAYERS_COUNT];


    return 0;
}