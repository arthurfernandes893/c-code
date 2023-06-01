#include <stdio.h>

//escopo das funcoes que serao usadas 
int checkBissexto (int);

int main (){
    //definicao das variaveis
    int d,m,a,aux,dias ;

    //leitura dos valores
    scanf("%d", &d);
    scanf("%d", &m);
    scanf("%d", &a);

    // calculo dos dias relacionado aos meses passados
     if (m==01){
        aux = 0;
    }
    else if (m == 02){
        aux = 31;
    }
    else if (m == 03){
        aux =59;
    }
    else if (m == 04){
        aux = 90;
    }
    else if (m == 05){
        aux = 120;
    }
    else if (m == 06){
        aux = 151;
    }
    else if (m == 07){
        aux = 181;
    }
    else if (m == 8){
        aux = 212;
    }
    else if (m == 9){
        aux = 243;
    }
    else if (m == 10){
        aux = 273;
    }
    else if (m == 11){
        aux = 301;
    }
    else if (m == 12){
        aux = 334;
    }
    
    
    //soma dos dias antes e depois de fevereiro. se bissexto faz o acrescimo
     if (m>02)
    {
        dias = aux + d + checkBissexto(a);    
    }
    else{
        dias = aux + d;
    }

    printf ("%d\n",dias);
   
    return 0;
}

int checkBissexto (int ano){
    if (ano %4 == 0){
        return 1;
    }
    else{
        return 0;
    }
}




