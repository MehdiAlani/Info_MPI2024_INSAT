#include <stdio.h>


int main(){
    int nb = 0;
    short Valide;
    char c;
    char *message;
    do{
    do{
        c = getchar();
        message[nb] = c;
        nb++;
    }while(c != '#');
    printf("\n");
    Valide=1;
    for(int i = 0; i<nb;i++){
        if(message[i]<'A' || message[i]>'Z' && message[i] < 'a' || message[i] > 'z' && message[i]!='\n' && message[i]!=' '){
            Valide=0;
            break;
        }
        printf("%c",message[i]);
    }
    }while(Valide == 0);

    return 0;
}