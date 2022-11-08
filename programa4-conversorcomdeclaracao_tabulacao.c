#include <stdio.h>
float conversor(float );

int main()
{
    float tempinicio, tempfim, incremento;
    scanf("%f",&tempinicio);
    scanf("%f",&tempfim);
    scanf("%f",&incremento);
    for(tempinicio;tempinicio<=tempfim;tempinicio+=incremento)
    {

        printf("%f\t%f\n", tempinicio, conversor(tempinicio));     

    }

}

float conversor (float celsius) 
{
    	return (celsius*(9.0/5.0))+32.;
}
