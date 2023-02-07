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
    float horas;
    float salario;
};

int registra_dados(struct funcionarios* , FILE* );
int workedhours(struct workedh*, FILE*);
int income(struct funcionarios*, struct workedh*);

int main(){
    // abertura do barquivos//
    FILE* emp = fopen("Funcionarios.txt", "r");
    FILE* job = fopen("Novembro.txt", "r");
    
    //declaracao dos structs e seus apontadores//
    struct funcionarios func[10];
    struct workedh trab[10];
    struct funcionarios* pfunc = func;
    struct workedh* ptrab = trab ;
   
    registra_dados(pfunc,emp);
    workedhours(ptrab,job);
    income(pfunc,ptrab);
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

    for(int j =0;j<10;j++){
        printf("%s|",(pfunc+j)->nome);
        printf("%s|",(pfunc+j)->matricula);
        printf("%s|",(pfunc+j)->endereco);
        printf("%s|",(pfunc+j)->cpf);
        printf("%s|",(pfunc+j)->banco);
        printf("%s|",(pfunc+j)->agencia);
        printf("%s|",(pfunc+j)->conta);
        printf("%.2f",((pfunc+j)->valor));
        printf("\n");
    }
    printf("\n");
    return 0;
    
}

int workedhours(struct workedh* ptrab, FILE* job){
    //ler e pular a barra//
    char bar[2];
    char* pbar = bar;

    //ler,converter e armazenar as horas como int//
    char hours[5]; //ler 5 pois pdoe haver 3 caracteres+\n+\0//
    char* phours = hours;
    float numaux;
    float* pworkedhours = &numaux;
    for(int i=0; i<10;i++){
        fgets((ptrab+i)->id,13,job);
        fgets(pbar,2,job);
        fgets(phours,5,job);
        sscanf(phours,"%f",pworkedhours);
        (ptrab+i)->horas = *pworkedhours;
    }

    for(int j =0; j<10; j++){
        printf("%s\t%f\n",(ptrab+j)->id,((ptrab+j)->horas));
    }
  
    printf("\n");
    return 0;
}

//usar funcao pra comprar as strings//

int income(struct funcionarios* pfunc, struct workedh* ptrab){
    //rodar busca e comparacao//
    //for(int i =0;i<10;i++){
        for(int j =0; j<10;j++){
            printf("%s e %s\n",ptrab->id,(pfunc+j)->matricula);
            printf("%d\n", (((ptrab)->id) == ((pfunc+j)->matricula)));
            printf("%f * %f = %f\n\n", ptrab->horas,(pfunc+j)->valor, ptrab->salario);        
            if(((ptrab)->id) == ((pfunc+j)->matricula)){
            
                ((ptrab)->salario) = ((ptrab)->horas)*((pfunc+j)->valor);
                printf("%f * %f = %f\n", ptrab->horas,pfunc->valor, ptrab->salario);
            }
        }
       // printf("%f",((ptrab)->salario));
    //}
    //associar valores//
    //calcular salario//
    //armazenar no struct//

    return 0;
}
