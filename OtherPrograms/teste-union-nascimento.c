#include <stdio.h>
#include <string.h>

//receber um input em char, converter pra int e operar.//

//1. fazer isso usando UNION//

union tag{
    char data[20];
    int caracteres;
};

union tag nascimento;
int atoi (char*);  // por que precisou declarar como apontador pra caractere????? //

int main(){
    strcpy(nascimento.data,"18");
    printf("impressao usando o union no modo de caractere: %s\n",nascimento.data);
    printf("impressao usando o modo inteiro de interpretar o dado: %d\n",nascimento.caracteres);
    printf("impressao usando a conversao do caractere para inteiro: %d\n\n",atoi(nascimento.data));

    //teste com ponteiros//
    union tag* pnasc;
    pnasc = &nascimento;
    printf("impressao do endereco do union: %p\n\n",pnasc);

    printf("impressao usando pnasc -> data: %s \n",pnasc->data);  //NAO PRECISA DO * pra se referir a modos do union//
    printf("impressao usando (*pnasc).data: %s \n",(*pnasc).data); // se for usar *, precisa estar entre () pra poder indicar o tipo depois com .data //
   //  printf("impressao usando *pansc: ",*pnasc); nao funciona pq o tipo union tag nao pode ser impresso, apenas os subtipos definidos, como no struct. //
    printf("impressao usando pnasc -> caracteres: %d \n",pnasc->caracteres);
    printf("impressao usando atoi(pnasc->data): %d \n",atoi(pnasc->data));

    return 0;
}

/* atoi: convert s to integer */
int atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
    n = 10 * n + (s[i] - '0');
    return n;
}