#include <stdio.h>

int printmat(int mat[][],int LIN,int COL){
    for(int a = 0;a< LIN;a++)
    {
        for(int b=0;b< COL;b++)
        {
            printf("%d ",mat[a][b]);
            
        }
        printf("\n");
    }
}

int bitabit(int valor){
// numero 1 eh transformado em "10000..." pra analisar do ultimo ao primeiro bit e retornar apenas 1 ou 0, indicando, pelo valor do indice, aquela posicao//
    for(unsigned int i = 1 << 31; i>0; i = i/2){ 
        if((valor & i)){ //imrpime o contrario, pois o operador bitabit retornar zero, significa que eh igual a 1 , logo, deve imprimir um//
            printf("1");
        }
        else{
            printf("0");
        }
    }
    printf("\n");

    return 0;
}