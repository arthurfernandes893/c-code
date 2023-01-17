#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* cabecalho(FILE*, char*,char* , char*, int*, int* , char*);
int registradora (FILE*,char*, char*);
int carregapixels(FILE*, char*,int*, int*, int*);

int main(){
//leitura do nome e error checking//
    char nome[50];
    fgets(nome,50,stdin);
    if(nome == NULL){
        perror("Erro: problema na leitura");
    }
//remocao do \n no final da string//
    char* p;
    if((p = strchr(nome, '\n'))){
        (*p) = '\0';
    }
//atribuicao do char[] a um char* pra entrar na fopen()//
    char* name;
    name = nome;

//abertura do arquivo//
    FILE* arq;
    arq = fopen(name,"r");
    if( arq == NULL){
        printf("Erro: arquivo inexistente\n");
        exit(1);
    }
//definicao das strings e variaveis com as partes do texto//
    char* tipo;
    char* comment;
    int linha,coluna;
    char* dimensionpixel;
    
    int* lin;
    int* col;
    lin = &linha;
    col = &coluna;

//array pra pegar a linha e entao trata-la dentro do programa//
    char texto[250];

//funcao que carrega as infos da imagem e retorna o array com os pixels, alocado dincamicamente//
    int* arraypixel = cabecalho(arq,texto,tipo,comment,lin,col,dimensionpixel);

//impressao//
    for(int i = 0; i<(*lin); i++){
        for(int j =0; j<(*col); j++){
            if(j==((*col)-1)){
                printf("%3X",*(arraypixel+(i*(*col)+j)));        
            }
            else{
                printf("%3X",*(arraypixel+(i*(*col)+j)));
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

int* cabecalho(FILE* arq, char* texto,char* tipo, char* comment, int* lin, int* col, char* dimensionpixel){
    registradora(arq,texto,tipo);
    registradora(arq,texto,comment);

    fgets(texto,250,arq);
    sscanf(texto,"%d %d",lin,col);
    
    registradora(arq,texto,dimensionpixel);

    int* pixels = malloc(sizeof(int)*((*lin)*(*col)));

    carregapixels(arq, texto, pixels,lin,col);
    return pixels;
}

int registradora (FILE* arq,char* texto, char* string){
    fgets(texto,250,arq);
    sscanf(texto,"%s",string);
    return 0;
}

int carregapixels(FILE* arq, char* texto,int* pixels,int* lin ,int* col){
    //definicao de auxiliares para o registro dentro do array.
    char* aux;
    int i;
    int j=0;
    //registro no array//
    for(i = 0; i<(*lin) ;i++){
        fgets(texto,250,arq);
        aux = NULL;
        aux = strtok(texto," \n");
        while(aux != NULL){
            sscanf(aux,"%d",(pixels+(i*(*col))+j));
            j++;
            aux = strtok(NULL," \n\0"); 
        }
        j=0;  //zera so o j pq so precisa zerar a linha//
    }   

    return 0;
}