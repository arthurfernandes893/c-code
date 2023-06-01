#include <stdio.h>


int main(){
//entre -128 e 127 eh char//
    char a,b,soma;
    
// leitura dos valores//
    scanf("%hhd",&a);
    scanf("%hhd",&b);

//soma dos valores
    soma = a + b;

//impressao dos valores//
    printf("%hhX %hhd\n", a, a);
    printf("%hhX %hhd\n", b, b);
    printf("%hhX %hhd\n", soma, soma);

    return 0;
}
