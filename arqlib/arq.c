#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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