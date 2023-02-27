#include <stdio.h>
#include <string.h>


struct funcionarios{
    char nome[51];
    char matricula[13];
    char endereco[66];
    char cpf[12];
    char banco[4];
    char agencia[6];
    char conta[9];
    float valor;
    float salario;
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
int ordenador(struct funcionarios*);

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
    ordenador(pfunc);
    imprime(folha, pfunc, ptrab);


    return 0;
}

int registra_dados(struct funcionarios* pfunc, FILE* emp){
   char barra[2];
   char* pb = barra;
   for(int i =0; i<10; i++){
    //leitura das infos//
        fgets(((pfunc+i))->nome,51,emp); //busca nome + espaco//
        fgets(pb,2,emp); //busca o espaco//
            
        fgets(((pfunc+i))->matricula,13,emp); //busca 12 char-- a partir daqui tem que buscar os espacos//
        fgets(pb,2,emp); //busca o espaco//

        fgets(((pfunc+i))->endereco,66,emp); //busca o endereco//
        fgets(pb,2,emp);

        fgets(((pfunc+i))->cpf,12,emp);
        fgets(pb,2,emp);

        fgets(((pfunc+i))->banco,4,emp);
        fgets(pb,2,emp);

        fgets(((pfunc+i))->agencia,6,emp);
        fgets(pb,2,emp);

        fgets(((pfunc+i))->conta,9,emp);
        fgets(pb,2,emp);

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
                ((pfunc+i)->salario) = ((ptrab+j)->salario);
            }  
        }
    }

    return 0;
}

int imprime(FILE* pfolha, struct funcionarios* pfunc, struct workedh* ptrab){
    
    for(int i =0;i<10;i++){
        printf("%s|%s|%s|%s|%s|%.2f\n",((pfunc+i)->nome), ((pfunc+i)->cpf), ((pfunc+i)->banco), ((pfunc+i)->agencia), ((pfunc+i)->conta), ((pfunc+i)->salario));
    }
    return 0;
}

int ordenador(struct funcionarios* pfunc){
    struct funcionarios aux;
    struct funcionarios* paux = &aux;
    for (int i = 1; i < 10; i++) { /* 3 = qtde de palavras */
    for (int j = 1; j < 10; j++) {
        // verifica se tem que ser depois, se for troca de posição
        if (strcmp((pfunc+(j - 1))->nome, (pfunc+j)->nome) > 0) {
            aux = pfunc[j - 1];
            pfunc[j - 1] = pfunc[j];
            pfunc[j] = aux;
        }
    }
}
    return 0;
}