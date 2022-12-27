#include <stdio.h>

int ordenador(int* ,int* );
int mdc(int,int);

int main(){
    int a, b;
    int* pa;
    int* pb;
    pa = &a;
    pb = &b;

    scanf("%d %d",&a,&b);
    
    ordenador(pa,pb);
    
    printf("%d\n",mdc(a,b));
    
    return 0;
}

int ordenador(int* a, int* b){
    int auxiliar = 0;
    if((*b) > (*a)){
        auxiliar = (*a);
        (*a) = (*b);
        (*b)= auxiliar;
        
    }
    return 0;
}

int mdc(int a, int b){
    int aux =1;
    while (aux != 0){
        aux = a % b;
        a = b;
        if(aux ==0){
            return b;
        }
        
        b = aux;
    }
}

