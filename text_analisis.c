#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arqlib/arq.h"
#include <ctype.h>

struct data{
    int numchar;
    int lines;
    int totalchar;
};

int analise(FILE*, struct data*);
int main(){
//leitura do nome//
    char nome[50];
    fgets(nome,50,stdin);
    if(nome == NULL){
        perror("Erro: problema na leitura");
    }

    char* p;
    if((p = strchr(nome, '\n'))){
        (*p) = '\0';
    }

    char* name;
    name = nome;
//abertura do arquivo//
    FILE* arq;
    arq = fopen(name,"r");
    if( arq == NULL){
        printf("Erro: arquivo inexistente\n");
        exit(1);
    }
//definicao do struct//
    struct data texto;
    struct data* ptexto = &texto;
//chamada da funcao e impressao//
    analise(arq,ptexto);
    printf("%d\n%d\n%d\n",texto.numchar,texto.lines,texto.totalchar);

    fclose(arq);
    return 0;
}

int analise(FILE* arq, struct data* text){
    char aux;
    aux = fgetc(arq);
    (text->lines) = 1;
    while(!feof(arq)){
    //uso do isprint para mostrar o que eh imprimivel//
        if(isprint(aux)){
            (text->numchar)++;    
        }
        if(aux == '\n'){
            (text->lines)++;
        }
        
        (text->totalchar)++;
        
        aux = fgetc(arq);
    }
    return 0;
}