#include <stdio.h>

int main(){
// inicializacao da matriz 3x3 e das variaveis auxiliares // 
    double mat[3][3];
    double determinante,l1=1,l2=1,l3=1,l4=1,l5=1,l6=1;

// insercao dos valores da matriz //
    for(int i=0;i<3;i++){
        for(int j =0;j<3;j++){
            scanf("%lf.",&mat[i][j]);
        }
    }

// formacao da matriz com as colunas copiadas pra calcular determinante //
    double matDet[3][5]; 
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

     for(int a = 0;a<3;a++)
    {
        for(int b=0;b< 3;b++)
        {
            printf("%lf ",mat[a][b]);
            
        }
        printf("\n");
    }


// impressao do determinante mostrando as somas //    
    printf("%lf\n",determinante);

    return 0;
}

