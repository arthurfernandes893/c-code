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
int imprime(struct registro*);
int apagalista(struct registro** p);
int apagaelem(struct registro* elem, struct registro** head);
struct registro* buscaelem(struct registro* p, char name[50],int age, int number,double gpa);
int imprime_esp_elem(struct registro* head);

int main(){
    struct registro* phead = NULL;
    insereinicio(&phead);
    for(int i =0; i<3; i++){
    inserefim(&phead);
    }

    char aaux[50] = "aaa";
    char baux[50] = "bbb";
    imprime(phead);
    printf("\n");
    apagaelem(buscaelem(phead,aaux,13,132,132.0),&phead);
    imprime(phead);
    printf("\n");
    imprime_esp_elem(buscaelem(phead,baux,12,13,132.0));
    apagalista(&phead);


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

int imprime(struct registro* head){
    //toda a lista//
    if(head){ //se o elemento apontado nao for nulo, imprimir seus elementos e chamar recursivamente pra rodar a lista//
        printf("%s|%d|%d|%lf\n",((head)->nome), ((head)->idade), ((head)->matricula), ((head)->cr));        
        imprime(((head)->next));
    }
    else{
        printf("FIM DA LISTA\n");
    }
    return 0;
}

int imprime_esp_elem(struct registro* head){
    printf("%s|%d|%d|%lf\n",((head)->nome), ((head)->idade), ((head)->matricula), ((head)->cr));



    return 0;
}

int apagalista(struct registro** p){ //usa indirecao dupla porque precisa acessar as infos e no fim acessar phead//
    //percorrer a lista ate o ultimo e ir desalocando do ultimo ao primeiro//
    if(*p){
        apagalista(&(*p)->next);
        free(*p);
        (*p) = NULL;     
    }
    return 0;
}

int apagaelem(struct registro* elem, struct registro** head){ 
    if(*head){
        if((*head) == elem){
            *head = elem->next;
            free(elem);
        }
        else{
            apagaelem(elem, &(*head)->next);
        }
    }
    else{
        printf("elemento nao encontrado");
    }
    return 0;
}

struct registro* buscaelem(struct registro* p, char name[50],int age, int number,double gpa){
    if(p){  //se nao for nulo, procure//
        if((strcmp((p)->nome,name)) && ((p)->idade == age) && ((p)->matricula == number) && ((p)->cr == gpa)){
            //comparar os campos do elemento e se for retorna o apontador pra esse elemento//
            return (p);
        }
 
        else{
            buscaelem((p->next), name,age, number,gpa);
        }
    }
    else{
        return NULL;
    }
}

