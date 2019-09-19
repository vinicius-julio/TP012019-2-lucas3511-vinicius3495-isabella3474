#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_MatEsparca.c"
#include "TAD_Produto.c"

int main() {
    int i, j, linha, coluna;
    double valor;
    int checkfunctionL, checkfunctionC, checkfunctionM;
    TCelula *celula;
    TLisprod lisprod;
    TProdutos produtos;
    TLista lista;
    int cod_op;

    printf("Digite o numero de linhas\n");
    scanf("%d", &i);
    printf("Digite o numero de colunas\n");
    scanf("%d", &j);

    //Inicializa lista
    InicializaProd(&lisprod);
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

    do{
        printf("Entre com a operacao desejada:\n");
        printf("*****************************************\n");
        printf("| Codigos de operacao:                  |\n");
        printf("| 1 - Insere dados de compra            |\n");
        printf("| 2 - Imprime Matriz                    |\n");
        printf("| 3 - Imprime cabecas                   |\n");
        printf("| 4 - Inserir Compra                    |\n");
        printf("| 5 - Imprime lista de compra           |\n");
        printf("| 0 - Encerra                           |\n");
        printf("*****************************************\n");
        fflush(stdin);
        scanf("%d", &cod_op);
        if(cod_op == 1){
            printf("Insira os dados da celula (linha, coluna e valor)\n");

            scanf("%d %d %s %d", &linha, &coluna, produtos.datacompra, &produtos.qtdproduto);

            InsereMatriz(&lista, i, j, coluna, linha, &produtos);
        }
        else if(cod_op == 2){
            printf("%d\n", lista.principal->abaixo->abaixo->abaixo->direita->direita->linha);
            printf("%d\n", lista.principal->abaixo->abaixo->abaixo->direita->direita->coluna);

            printf("%d\n", lista.principal->abaixo->abaixo->direita->direita->linha);
            printf("%d\n", lista.principal->abaixo->abaixo->direita->direita->coluna);

            printf("%d\n", lista.principal->abaixo->abaixo->direita->direita->direita->linha);
            printf("%d\n", lista.principal->abaixo->abaixo->direita->direita->direita->coluna);
            ImprimeMatriz(&lista, linha);
        }
        else if(cod_op == 3){
            ImprimeMatrizL(&lista, i);
            ImprimeMatrizC(&lista, j);
        }
        else if(cod_op == 4){
            scanf("%d %s", &produtos.qtdproduto, produtos.datacompra);
            Insere(&lisprod, &produtos);
        }
        else if(cod_op == 5){
            Imprime(&lisprod);
        }
    }while(cod_op != 0);

    /*
    //Entrada por Arquivo
    char nome_arq[100];
    char texto[1000];
    scanf("%s", &nome_arq);
    FILE *ptr_arq;
    ptr_arq = fopen(nome_arq, "r");
    while(strcpy(texto, ptr_arq) != NULL) {
        printf("%s", texto);
    }
     */
    return 0;
}