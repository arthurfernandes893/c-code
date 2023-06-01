#include <stdio.h>
#include <string.h>

int printmat(int*); // problema no compilador!!!!//

int main () {
    int list[] = {1,2,3,4,5,6,7,8,9};
    int* plist;

    //teste com o array de uma dimensao//
    printf("esse eh o teste com o array de uma dimensao:\n");
    for (int i = 0; i < 9; i++)
    {
        plist = list;
        printf("%d eh o elemento do array e %p eh o seu endereco\n\n",list[i],plist+i);
    }
    printf("\n");

    //teste com o array de duas dimensoes//
    printf("esse eh o teste com o array de duas dimensoes:\n");
    int mat[2][10] = {{1,2,3,4,5,6,7,8,9,10},{11,22,33,44,55,66,77,88,99,100}};
    int* pmat;

    pmat = &mat; // como evitar o aviso de erro do compilador????//

    printmat(mat);


    return 0;
}

int printmat (matriz){
    for(int i=0; i<2; i++)
    {
        for(int j=0; j<10; j++){
            printf("%d\t",matriz[i][j]);
            if (j == 9)
            {
                printf("\n");
            }
            
        }
    }
    return 0;
}