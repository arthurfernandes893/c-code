#include <stdio.h>


int main () {
    FILE* arq;
    FILE* erro;
    arq = fopen("binario.txt","r");
    if(arq == NULL){
        perror("deu ruim abertura arquivo erro\n");
    }
   
    char* a = "\n aaaaaaaaaaaaa\n";
/*
    for(int i =0; i<20;i++){
        fputs(a, arq);
        if(ferror(arq)){
            perror("erro na impressao");
        }
    }
    fflush(arq);
*/
    printf("%li\n",ftell(arq)); //imprime posicao atual do apontador//
    //rewind(arq); //zera posicao pro inicio//
    //printf("%li\n",ftell(arq)); //imprime a posicao zero//
    
    fseek(arq,0,SEEK_END); //altera a posicao do apontador//
    printf("%li\n",ftell(arq)); //imprime posicao alterada

    //char b[2025];
    //fgets(b,40,arq); //busque 10 caracteres no arquivo b//
/*
    char* c = "bbbbbbbbbbbbbbb";
    fputs("......",arq);
    if(ferror == 0){
        perror("erro de leitura");
    }

    printf("posicao no arquivo: %li. e elemento em questao:  \n",ftell(arq) );
    fclose(arq);

  */   


return 0;
}

