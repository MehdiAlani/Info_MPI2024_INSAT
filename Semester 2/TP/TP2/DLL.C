#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 10
#define NB_MAX 100

typedef struct noued{
    int valeur; 
    struct noued * p_next;
    struct noued * p_prev;
}noued;
typedef noued * liste_ch;

liste_ch Creation(){
    return NULL;
}

liste_ch inserer(liste_ch L , int val,int pos){
    liste_ch p = (liste_ch) malloc(sizeof(noued));
    p -> p_next = NULL;
    p -> p_prev = NULL;
    p -> valeur = val;
    if(L == NULL) return p;
    if (pos == 1) {
        p -> p_next = L;
        L -> p_prev = p;
        return p;
    }
    int i = 2;
    liste_ch move = L;
    while (i < pos && move -> p_next  != NULL){
        move = move -> p_next;
        i++;
    }
    
    p -> p_next = move -> p_next;
    p -> p_prev = move;
    move -> p_next = p;
    return L;
}
liste_ch Suppression(liste_ch L,int pos){
    if(L == NULL) return NULL;
    liste_ch move = L;
    if(pos == 1) {
        move = L -> p_next;
        free(L);
        return move;
    }
    int i = 1;
    while(i < pos && move -> p_next != NULL){
        move = move -> p_next; 
        i++;
    }
    move -> p_prev -> p_next = move -> p_next;
    free(move);
    return L;
}
int leng(liste_ch L){
    if(L == NULL) return 0;
    int n = 0;
    liste_ch move = L;
    while( move != NULL){
        move = move -> p_next;
        n++;
    }
    return n;
}
void Affichage(liste_ch L){
    printf("\n");
    liste_ch move = L;
    while (move != NULL){
        printf("%d ",move -> valeur);
        move = move -> p_next;
    }
    printf("\n");
    return;
}
void Affichage_2(liste_ch L,int pos){
    if(pos == 1) {
        printf("NULL %d %d\n",L -> valeur,L -> p_next -> valeur);
        return;
    }  
    int i = 1;
    liste_ch move = L;
    while(i != pos) {
        move = move -> p_next;
        i++;
    }
    if(move -> p_next == NULL){
        printf("%d %d NULL\n",move -> p_prev -> valeur,move -> valeur);
        return;
    }
    printf("%d %d %d\n",move -> p_prev -> valeur,move -> valeur,move -> p_next -> valeur);
    return;
}
int main(){
    srand(time(NULL));
    liste_ch L = Creation();
    int i;
    int random_nb = rand() % NB_MAX;
    for(i = 1; i <= TAILLE; i++){
        L = inserer(L,random_nb,i);
        random_nb = rand() % NB_MAX;
    }
    printf("La Liste de taille %d est : ",leng(L));
    Affichage(L);

    L = Suppression(L,2);
    Affichage(L);
    
    L = Suppression(L,1);
    Affichage(L);
    L = Suppression(L,2);
    Affichage(L);

    Affichage_2(L,7);
    
    return 0;
}