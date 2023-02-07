#include <stdio.h>
#include <string.h>

struct funcionarios{
    char nome[50];
    char matricula[12];
    char endereco[65];
    char cpf[11];
    char banco[3];
    char agencia[5];
    char conta[8];
    float valor;
};

struct worked_h{
    char id[11];
    int horas;
};

int leitora(struct funcionarios* func, struct worked_h* trab, FILE* emp, FILE* job){
    
   
}