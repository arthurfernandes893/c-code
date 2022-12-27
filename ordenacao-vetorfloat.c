#include <stdio.h>
#include <stdlib.h>



int main(){
//quantidade de valores//
    int quant;
    scanf("%d",&quant);

//alocacao da memoria//
    float* pvet;
    pvet = malloc(quant*sizeof(float));  

//leitura dos dados//
    for(int w=0; w<quant; w++)
    {
        scanf("%f",(pvet+w));
    }



// ordenacao //
   for (int i = 0; i < quant; i++)                    
	{
		for (int j = 0; j < quant; j++)             
		{
			if (pvet[j] < pvet[i])                
			{
				float tmp = pvet[i];         
				pvet[i] = pvet[j];            
				pvet[j] = tmp;             
			}
		}
	}
	
// impressao //
    for(int z=0;z<quant;z++){
        printf("%f ",pvet[z]);
   }
   printf("\n");

// liberacao da memoria alocada//
    free(pvet);

    return 0;
}


