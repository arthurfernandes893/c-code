//teste de impressao de strings usando o modo de array e o modo apontador//

#include <stdio.h>
#include <string.h>

struct tag
{
    char nome[20];
    char sobrenome[20];
    int idade;
    char nascimento[10];
};

struct tag cadastro;
int print (struct tag info);

int main (){
//inicializacao do apontador p[ro struct//
    struct tag* pcadastro = &cadastro;

//inicializacao do apontador pro apontador//
    struct tag* apontador = &pcadastro;
   
//insercao dos valores copiando a string da direita para a da esquerda//
    strcpy(cadastro.nome,"Janio");
    strcpy (cadastro.sobrenome,"Quadros");
    cadastro.idade = 45;
    strcpy(cadastro.nascimento,"18/12/1956");

//impressao dos dados de diferentes formas//
    printf("\n esse eh o print usando o convencional: %s",cadastro.nome);
    printf("\n esse eh o print usando apontador: %s", (*pcadastro).nome);
    printf("\n esse eh print usando apontador do jeito p-->: %s \n", pcadastro->nome);
    print(cadastro);

//impressao dos enderecos//
    for(int i=0; i<4;i++){
        printf("esse eh o endereco %p\n",pcadastro+i);
    }

//impressao do endereco do apontador//
    printf("endereco do apontador: %p\n",apontador);

    return 0;
}

int print (struct tag info){
    printf("\n %s  %s, %d. \n Nascido em: %s \n\n",info.nome,info.sobrenome,info.idade,info.nascimento);
    return 0;
}