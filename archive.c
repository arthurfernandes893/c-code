#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>

int learquivo(char*, FILE*, char*[][50]);
int separador(char*,char*[][50]);

int main(){
   
    //nome do arquivo//
    char nome[30]; 
    scanf("%s",nome);

    printf("%s\n",nome);

//abertura do arquivo//
    FILE * arq;
    arq = fopen(nome, "r+");
    if(ferror(arq) != 0){
        perror("Erro: arquivo inexiste\n");
        
    }

//alocacao dinamica do array//
    fseek(arq,0,SEEK_END);
    int pos = ftell(arq);
    printf("%d",pos);
    rewind(arq);

    char* texto = malloc(pos*sizeof(char));

//leitura do arquivo e separacao em palavras//
    char* palavras[200][50];

learquivo(texto,arq,palavras);
for(int i =0;i<10;i++){
    printf("%s ",palavras[0][i]);
}
    fclose(arq);
    return 0;
}

int learquivo(char* texto, FILE* arq, char* palavras[][50]){
//leitura do arquivo para um array com os textos//
    fscanf(arq,"%s",texto);
    if(ferror(arq)){
        perror("problema na leitura do arquivo");
        exit(2);
    }
    //separacao das palavras//
    separador(texto,palavras);

return 0;
}

int separador(char* texto,char * palavras[][50]){
    char* aux = strtok(texto," ,.;:*\t\n");
    int i = 0;
    while(aux!=NULL){
        strcpy(palavras[i],aux);
        //palavras[i] = aux;
        i++;
        aux = strtok(NULL," ,.;:*\t\n");
    }



return 0;
}

