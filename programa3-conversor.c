#include <stdio.h>
float conversor(float );

int main()
{
	float tempcelsius;
    tempcelsius =-10;
	for (tempcelsius=-10;tempcelsius<=50;tempcelsius+=10)
    {
	// nao precisa chamar a funcao antes. so precisa colocar o printf e a funcao dentro do print. pq a funcao conversor nao mantem esse valor. 	
		printf("%f\n",conversor(tempcelsius));		
	}
}

float conversor (float tempcelsius)
{
	return (tempcelsius*(9.0/5.0))+32.;
}	
