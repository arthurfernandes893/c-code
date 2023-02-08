#include <stdio.h>
#include <string.h>


struct funcionarios{
    char nome[52];
    char matricula[13];
    char endereco[68];
    char cpf[13];
    char banco[5];
    char agencia[7];
    char conta[10];
    float valor;
};

struct workedh{
    char id[13];
    int horas;
    float salario;
};

int registra_dados(struct funcionarios* , FILE* );
int workedhours(struct workedh*, FILE*);
int income(struct funcionarios*, struct workedh*);
int imprime(FILE*, struct funcionarios*, struct workedh*);

int main(){
    // abertura do barquivos//
    FILE* emp = fopen("Funcionarios.txt", "r");
    FILE* job = fopen("Novembro.txt", "r");
    FILE* folha = fopen("folha_pagamento.txt","w");
    //declaracao dos structs e seus apontadores//
    struct funcionarios func[10];
    struct workedh trab[10];
    struct funcionarios* pfunc = func;
    struct workedh* ptrab = trab ;
   
    registra_dados(pfunc,emp);
    workedhours(ptrab,job);
    income(pfunc,ptrab);
    imprime(folha, pfunc, ptrab);


    return 0;
}

int registra_dados(struct funcionarios* pfunc, FILE* emp){
   for(int i =0; i<10; i++){
    //leitura das infos//
        fgets(((pfunc+i))->nome,52,emp);
        fgets(((pfunc+i))->matricula,13,emp);
        fgets(((pfunc+i))->endereco,68,emp);
        fgets(((pfunc+i))->cpf,13,emp);
        fgets(((pfunc+i))->banco,5,emp);
        fgets(((pfunc+i))->agencia,7,emp);
        fgets(((pfunc+i))->conta,10,emp);

    //leitura do valor por hora e sua conversao p float//
        char aux[50];
        char* paux = aux;    
        fgets(paux,50,emp);
        float num;
        float* pnum = &num;
        sscanf(paux,"%f",pnum);
        (pfunc+i)->valor = *pnum;
    //impressao dos valores na forma desejada//
        
    }
    return 0;
    
}

int workedhours(struct workedh* ptrab, FILE* job){
    //ler e pular a barra//
    char bar[2];
    char* pbar = bar;

    //ler,converter e armazenar as horas como int//
    char hours[5]; //ler 5 pois pdoe haver 3 caracteres+\n+\0//
    char* phours = hours;
    int numaux;
    int* pworkedhours = &numaux;
    for(int i=0; i<10;i++){
        fgets((ptrab+i)->id,13,job);
        fgets(pbar,2,job);
        fgets(phours,5,job);
        sscanf(phours,"%d",pworkedhours);
        (ptrab+i)->horas = *pworkedhours;
    }
    return 0;
}

int income(struct funcionarios* pfunc, struct workedh* ptrab){
    for(int j =0;j<10;j++){
        for(int i = 0;i<10;i++){
            //comparacao das strings--adicionar indices dos loops pra variar nos arrays//
            int k = strcmp((ptrab+j)->id,(pfunc+i)->matricula);
            if(k==0){
                //se achar uma igualdade,salario eh calculado e salvo no struct correspondente//
                ((ptrab+j)->salario) = ((ptrab+j)->horas)*((pfunc+i)->valor);
            }  
        }
    }

    return 0;
}

int imprime(FILE* pfolha, struct funcionarios* pfunc, struct workedh* ptrab){
    
    for(int i =0;i<10;i++){
        fprintf(pfolha,"%s|%s|%s|%s|%s|%f\n",((pfunc+i)->nome), ((pfunc+i)->cpf), ((pfunc+i)->banco), ((pfunc+i)->agencia), ((pfunc+i)->conta), ((ptrab+i)->salario));
    }
    return 0;
}