#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
//declaracao//
    int contador =0;
    char frase[1025];
    char* aux; // strtok retorna um apontador para o primeiro token. o certo eh ir tokenizando consecutivamente.//

//leitura da frase usando fgets que limita a quantidade//
    fgets(frase,1025,stdin);

//primeira rodagem de strtok//
    aux = strtok(frase," ,.;:   ");
//loop de tokenizacao e checagem pra incrementar//
    while(aux!=NULL){
        ++contador;
        aux = strtok(NULL," ,.;:\t\n");
    }
//impressao//
    printf("%d\n",contador);

    return 0;
}