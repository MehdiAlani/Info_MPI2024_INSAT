#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct el{
    int val;
    struct el * suviant;
}el;

typedef el * pile; 

pile cree(){
    return NULL;
}
int tete(pile * p){
    if(*p != NULL) return (*p) -> val;
}
void empiler(pile * p, int val){
    pile aux =(pile) malloc(sizeof(el));
    aux -> val = val;
    aux -> suviant = *p;
    *p = aux; 
}
void depiler(pile * p){
    if(*p == NULL) return;
    pile aux = (*p) -> suviant;
    free(*p);
    *p = aux;
}
void affiche(pile *p){
    pile aux = cree();
    int x;
    while((*p) != NULL){
        x = tete(p);
        depiler(p);
        printf("%d ",x);
        empiler(&aux,x);
    }
    printf("\n");
    while(aux != NULL){
        x = tete(&aux);
        empiler(p,x);
        depiler(&aux);
    }
    return;
}
int balance(const char * ch){
    int n = strlen(ch);
    int i;
    pile p = cree();
    for(i = 0; i < n; i++){
        if(ch[i] == '('){
            empiler(&p,1);
        }
        else if(ch[i] == ')'){
            if(p == NULL) return 0;
            else depiler(&p);
        }
    }
    return (p == NULL);
}
int pos(const char * ch){
    int n = strlen(ch);
    int i; 
    pile p = cree();
    for(i = 0; i < n; i++){
        if(ch[i] == '('){
            empiler(&p,i);
        }
        else if (ch[i] == ')'){
            if(p == NULL) return i;
            else depiler(&p);
        }
    }
    if(p == NULL) return -1;
    while(p != NULL){
        i = tete(&p);
        depiler(&p);
    }
    return i;
}

#define CHAINE  "())()"
int main(){
    const char * ch = CHAINE;
    printf("%d\n",pos(ch));
}