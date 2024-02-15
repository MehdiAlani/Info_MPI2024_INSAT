#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Neoud{
    int valeur; 
    struct Neoud * suivant;
}Noued;
typedef Noued * List;

List Creer(void){
    List list = (List) malloc(sizeof(Neoud));
    list -> suivant = NULL;
    return list;
}
List Inserer(List list,Noued * Champ , int position){
    if (position < 0) {
        printf("Position Invalide\n");
        exit(1);
    }
    else if (position == 0){
        Champ -> suivant = list;
        return Champ; 
    }
    else{
        int i = 0;
        Noued * p = list;
        while(i < position && p -> suivant != NULL){
            p = p -> suivant;
            i++; 
        }
        if(i < position){
            printf("Position Invalide\n");
            exit(1);
        } 
        Champ -> suivant = p -> suivant;
        p -> suivant = Champ;
        return list;  
    }
}

List Supprimer(List list,int position){
    Noued * p ;
    if (position < 0) {
        printf("Position Invalide\n");
        exit(1);
    }
    else if (position == 0){
        p = list -> suivant;
        free(list);
        return p; 
    }
    else{
        int i = 0;
        p = list;
        while(i < position - 1 && p -> suivant != NULL){
            p = p -> suivant;
            i++;
        }
        if(i < position - 1){
            printf("Position Invalide \n");
            exit(1);
        }
        p -> suivant = p -> suivant -> suivant;
        free(p -> suivant);
        return list;
    }
}

int Len(List list){
    if (list == NULL) return 0;
    else {
        int i = 0;
        Noued * p = list;
        while (p != NULL){
            p = p -> suivant;
            i++;
        } 
        return i;
    } 
}


void Affiche(List list){
    Noued * p = list;
    while(p != NULL){

        printf("%d ",p -> valeur);
        p = p -> suivant;

    }
}


#define TAILLE_LIST_MAX 100
#define MAX_NB 255
int main(){
    srand(time(NULL));
    List list = Creer();
    int n =  rand() % TAILLE_LIST_MAX;
    int i ;
    Neoud * p1 = list , * p2;
    for(i = 0; i < n; i++){
        p2 = Creer();
        p1 -> valeur = rand() % MAX_NB;
        p1 -> suivant = p2;
        p1 = p2;
    }
    p2 -> valeur = rand() % MAX_NB;
    p2 -> suivant = NULL;
    printf("Votre List est => \n");
    Affiche(list);

    int postion = 0;
    Noued * noued = (Noued *) malloc(sizeof(Noued));  
    noued -> valeur  = 9999;
    
    list = Supprimer(list,postion);
    printf("La Liste devint :\n");
    Affiche(list);


    return 0;
}
