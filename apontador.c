#include <stdio.h>

int incrementa(int*);

int main(){
    int num;
    int* pnum;

    pnum = &num;

    scanf("%d",&num);
    incrementa(pnum);
    printf("%d\n",num);
    return 0;
}

int incrementa(int* valor){
    ++(*valor);

    return 0;   
}