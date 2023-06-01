#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct pgm{
    char tipo[3];
    char comment[300];
    int linha;
    int coluna;
    char* pixel;
};


int registraDados(FILE*,char[], struct pgm, int *);
int imprime(struct pgm, int*);
int converte(FILE*, char[],int*);

int main (){
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
        printf("Erro,arquivo inexistente\n");
        exit(1);
    }

//infos da imagem//
    struct pgm imagem;
    char texto[250];
    //alocacao do array dinamico//
    int* pixels = malloc(sizeof(int)*(imagem.coluna*imagem.linha));
    
    //funcao registra e armazenamento dos pixels ja como int//
    registraDados(arq,texto,imagem, pixels);

    //impressao//
    imprime(imagem, pixels);

    //liberacao de memoria e fechamento de arquivo//
    free(pixels);
    fclose(arq);
    return 0;

}

int registraDados(FILE* arq, char texto[],struct pgm img, int* pixels){
    fgets(texto,250,arq);
    sscanf(texto,"%s",img.tipo);
    
    fgets(texto,250,arq);
    sscanf(texto,"%s",img.comment);
    
    fgets(texto,250,arq);
    sscanf(texto,"%d %d",&img.linha,&img.coluna);
    
    fgets(texto,250,arq);
    sscanf(texto,"%s",img.pixel);

    converte(arq, texto,pixels);
    return 0;
}

int converte(FILE* arq, char texto[],int* pixels){
    fgets(texto,250,arq);
    char* aux;
    aux = strtok(texto," \n");
    int i =0;
    while(aux != NULL){
        sscanf(aux,"%d",pixels[i]);
        i++;
        aux = strtok(NULL," \n");
    }


    return 0;
}

int imprime(struct pgm img, int* pixel){
    printf("%s\n",img.tipo);
    printf("%s\n",img.comment);
    printf("%d %d\n",img.linha,img.coluna);
    printf("%s\n",img.pixel);
   
    int jump = 0;
    for(int i = 0; i < (img.linha*img.coluna); i++){
        printf("%3X",pixel[i]);
        jump++;
        if(jump == 9){
            printf("\n");
            jump = 0;
        }
        else{
            printf(" ");
        }
        
    }
}