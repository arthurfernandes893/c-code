#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct registro{
    char nome[50];
    int idade;
    int matricula;
    double cr;
    struct registro* next;
};

int insereinicio(struct registro**);
int inserefim();
struct registro* criaelem(char*, int, int, double);
int imprime(struct registro**);

int main(){
    struct registro* phead = NULL;
    insereinicio(&phead);
    inserefim(&phead);
    imprime(&phead);
    return 0;
}

int insereinicio(struct registro** head ){ //struct registro** pode ser o endereco do apontador phead//
    //armazenamento temporario das infos pra inserir//
    char auxnome[50];
   
    int auxidade,auxmatricula;
    double auxcr;
    scanf("%s",auxnome);
    scanf("%d",&auxidade);
    scanf("%d",&auxmatricula);
    scanf("%lf",&auxcr);
    //criar novo elemento//
    struct registro* n_elem = criaelem(auxnome,auxidade,auxmatricula,auxcr);
    n_elem->next = *head;
    *head = n_elem;
    return 0;
}

int inserefim(struct registro** pelem){
    //percorrer a lista ate achar o ultimo elem//
    if(*pelem){ //se existe, se nao for null//
        inserefim(&((*pelem)->next)); // recursao passando o endereco do elemento apontado por head no campo next ate achar null e executar com aquele head q for null o else//
    }
    else{
        //armazenamento temporario das infos pra inserir//
        char auxnome[50];
    
        int auxidade,auxmatricula;
        double auxcr;
        scanf("%s",auxnome);
        scanf("%d",&auxidade);
        scanf("%d",&auxmatricula);
        scanf("%lf",&auxcr);

        //criar novo elemento//
        struct registro* n_elem = criaelem(auxnome,auxidade,auxmatricula,auxcr);
        n_elem->next = NULL; //campo next do ultimo elem recebe NULL//
        *pelem = n_elem; //o campo next do elemento em questao agora recebe o endereco do ultimo elemento. por isso passa-se o endereco do apontador next//
    }
    return 0;
}

struct registro* criaelem(char* auxnome, int auxidade, int auxmatricula, double auxcr){
    // criacao do novo elem//
    struct registro* n_elem = malloc(sizeof(struct registro));
    //associacao dos temporarios aos campos do novo elem//
    strcpy(n_elem->nome,auxnome); //copiar a string temporaria pro novo elemento de fato//
    n_elem->idade = auxidade;
    n_elem->matricula = auxmatricula;
    n_elem->cr = auxcr;

    return n_elem;
}

int imprime(struct registro** head){
    //primeiro elemento//
    //printf("%s|%d|%d|%lf\n",((*head)->nome), ((*head)->idade), ((*head)->matricula), ((*head)->cr));//

    //toda a lista//
  
    if(*head){ //se o elemento apontado nao for nulo, imprimir seus elementos e chamar recursivamente pra rodar a lista//
        printf("%s|%d|%d|%lf\n",((*head)->nome), ((*head)->idade), ((*head)->matricula), ((*head)->cr));        
        imprime(&((*head)->next));
    }
    
    //elemento em espefico//
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//    
    int index = 2;
     //chama recursivamente o numero de vezes//
        imprime(&((*head)->next));
        if(i == index-1){ //quando chegar nas rodagens desejadas imprimir e sair da funcao//
            printf("%s|%d|%d|%lf\n",((*head)->nome), ((*head)->idade), ((*head)->matricula), ((*head)->cr));
        }
    
    
    return 0;
}