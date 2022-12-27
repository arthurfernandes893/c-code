#include <stdio.h>

//se for p entrar como string, chamar funcao de converter p inteiro 
//e em seguida adicionar ao vetor bidimensional com for e 3 ifs dentro. ou so formatar a forma de entrada. //
//ou fazer for com tres scanf com "%d. %d. %d"//

int imprime (int*);

int main(){
// inicializacao da matriz 3x3 e das variaveis auxiliares // 
    int mat[3][3];
    int determinante,l1=1,l2=1,l3=1,l4=1,l5=1,l6=1;

// insercao dos valores da matriz //
    for(int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            scanf("%d.",&mat[i][j]);
        }
    }

// formacao da matriz com as colunas copiadas pra calcular determinante //
    int matDet[3][5]; 
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            matDet[i][j] = mat[i][j];  
        }
        for (int k = 3; k<5; k++)
        {
            matDet[i][k] = mat[i][k-3];
        }
    }

 
 // calculo das diagonais usando regra de sarrus // 
    for(int i =0; i<3; i++)
    {
        l1 *= matDet[i][i];
        l2 *= matDet[i][i+1];
        l3 *= matDet[i][i+2];
        l4 *= matDet[i][5-1-i];
        l5 *= matDet[i][5-2-i];
        l6 *= matDet[i][5-3-i];

    }

// soma dos valores //
    determinante = l1+l2+l3-l4-l5-l6;

// impressao do determinante mostrando as somas //    
    printf("%d\n",determinante);

    return 0;
}

