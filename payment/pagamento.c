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

struct workedh{
    char id[12];
    int horas;
};

int leitora(struct funcionarios* , FILE* );
int main(){
    // abertura do barquivos//
    FILE* emp = fopen("Funcionarios.txt", "r");
    FILE* job = fopen("Novembro.txt", "r");
    //declaracao dos structs e seus apontadores//
    struct funcionarios func[10];
    struct workedh trab[10];
    struct funcionarios* pfunc = func;
    struct workedh* ptrab = trab ;
    leitora(pfunc,emp);

    return 0;
}

int leitora(struct funcionarios* pfunc, FILE* emp){
    for(int i =0; i<10; i++){
        fgets(((pfunc+i))->nome,50,emp);
        fgets(((pfunc+i))->matricula,12,emp);
        fgets(((pfunc+i))->endereco,65,emp);
        fgets(((pfunc+i))->cpf,11,emp);
        fgets(((pfunc+i))->banco,3,emp);
        /*
        fgets(((pfunc+i))->agencia,5,emp);
        fgets(((pfunc+i))->conta,8,emp);
        char aux[50];
        char* paux;
        fgets(paux,5,emp);
        char* p;
        if((p = strchr(paux, '\n'))){
            (*p) = '\0';
        }
        sscanf(paux,"%f",((pfunc+i))->valor);        
    */
    }
    for(int i =0; i<10; i++){
        printf("%s  %s  %s  %s %s  \n",((pfunc+i))->nome, ((pfunc+i))->matricula, ((pfunc+i))->endereco, ((pfunc+i))->cpf );
    
    }
    return 0;
    
}