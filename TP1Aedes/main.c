#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_MatEsparca.c"
int main() {
    int i, j;
    int checkfunctionL, checkfunctionC, checkfunctionM;
    TCelula *celula;
    TLista lista;
    printf("Digite o numero de linhas\n");
    scanf("%d", &i);
    printf("Digite o numero de colunas\n");
    scanf("%d", &j);
    InicializaMatriz(&celula, &lista, i, j);
    checkfunctionL = InicializaLinha(&celula, &lista, i);
    checkfunctionC = InicializaLinha(&celula, &lista, i);
    checkfunctionM = InicializaLinha(&celula, &lista, i);
    if(checkfunctionL == 1 && checkfunctionC == 1 && checkfunctionM == 1){
        printf("linha inicializada com sucesso\n");
        printf("coluna inicializada com sucesso\n");
        printf("matriz incializada com sucesso\n");
    } else{
        printf("Matriz não inicializada\n");
    }
    printf("Hello, World!\n");
    return 0;
}