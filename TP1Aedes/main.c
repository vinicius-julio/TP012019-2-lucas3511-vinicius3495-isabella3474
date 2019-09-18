#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_MatEsparca.c"
int main() {
    int i, j;
    int checkfunctionL, checkfunctionC, checkfunctionM;
    TCelula *celula;
    TLista lista;
    TItem item;
    printf("Digite o numero de linhas\n");
    scanf("%d", &i);
    printf("Digite o numero de colunas\n");
    scanf("%d", &j);

    //Inicializa Matriz
    checkfunctionM = InicializaMatriz(&lista);
    //Células cabeça criadas a partir da principal de acordo com o número de linhas e colunas
    //Linhas
    checkfunctionC = InicializaColuna(&lista, j);
    //colunas
    checkfunctionL = InicializaLinha(&lista, i);



    if(checkfunctionL == 1 && checkfunctionC == 1 && checkfunctionM == 1){
        printf("Linha inicializada com sucesso...\n");
        printf("Coluna inicializada com sucesso...\n");
        printf("Matriz incializada com sucesso!\n");
    } else{
        printf("Matriz não inicializada\n");
    }
    ImprimeMatrizL(&lista, i);
    ImprimeMatrizC(&lista, j);

    return 0;
}