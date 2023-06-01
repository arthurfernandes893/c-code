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


int registraDados(FILE*,char[], struct pgm*, int *);
int imprime(struct pgm*, int*);
int converte(FILE*, char[], struct pgm*, int*);

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
    struct pgm* pimg;
    struct pgm* ponteiro;
    pimg = &imagem;
    char texto[250];
    //alocacao do array dinamico//
    int* apontador;
    
    
    //funcao registra e armazenamento dos pixels ja como int//
    registraDados(arq,texto,pimg, apontador);

    //impressao//
    imprime(pimg, apontador);

    //liberacao de memoria e fechamento de arquivo//
    free(apontador);
    fclose(arq);
    return 0;

}


int registraDados(FILE* arq, char texto[],struct pgm* pimg, int* apontador){
    fgets(texto,250,arq);
    sscanf(texto,"%s",(pimg->tipo));
    
    fgets(texto,250,arq);
    sscanf(texto,"%s",(pimg->comment));
    
    fgets(texto,250,arq);
    sscanf(texto,"%d %d",&pimg->linha,&pimg->coluna);
    printf("%d",(pimg->linha));
    fgets(texto,250,arq);
    sscanf(texto,"%s",(pimg->pixel));
    
    int* pixels = malloc(sizeof(int)*((pimg->coluna)*(pimg->linha)));
   
    //converte(arq, texto, pimg,pixels);//
    char* aux;
    for(int j = 0; j<(pimg->linha);j++){
        fgets(texto,250,arq);
        aux = NULL;
        aux = strtok(texto," \n\0");
        int i =0;
        while(aux != NULL){
            sscanf(aux,"%d",(pixels+i));
            i++;
            aux = strtok(NULL," \n\0");
        }    
    }
    

    //
   
    apontador = pixels;
    return 0;
}
/*
int converte(FILE* arq, char texto[], struct pgm* pimg, int* pixels){
    char* aux;
    for(int j = 0; j<(pimg->linha);j++){
        fgets(texto,250,arq);
        aux = NULL;
        aux = strtok(texto," \n");
        int i =0;
        while(aux != NULL){
            sscanf(aux,"%d",(pixels+i));
            i++;
            aux = strtok(NULL," \n");
        }    
    }
    
    return 0;
}
*/
int imprime(struct pgm* pimg, int* pixel){
    printf("%s\n",(pimg->tipo));
    printf("%s\n",(pimg->comment));
    printf("%d %d\n",(pimg->linha),(pimg->coluna));
    printf("%s\n",(pimg->pixel));
   
    int jump = 0;
    for(int i = 0; i < ((pimg->linha)*(pimg->coluna)); i++){
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