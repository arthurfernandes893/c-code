#include <stdio.h>

int main (){
    int mat;
    int* pmat;

    mat = 2;
    printf("%p seria o vetor sem nada\n",pmat);
    printf("%d seria um teste\n",mat);

    pmat = &mat;
    *pmat = ++mat;
    printf("%d eh a variavel mat incrementada. um teste apontando seria %d e %p o seu endereco\n",mat,*pmat,pmat);

}