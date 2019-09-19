#include "TAD_MatEsparca.h"
int InicializaColuna(TLista *lista, int j) {
    Apontador aux;
    int next;
    aux = lista->principal;
    for (next = 0; next < j; next++){
    aux->direita = (Apontador) malloc(sizeof(TCelula)); //Direita points to nova celula
    aux = aux->direita;                       //Ultimo points to nova celula
    aux->linha = 0;                                   //Valor da coluna é o mesmo de aux
    aux->coluna = -1;
    aux->direita = lista->principal;            //Direita(NC) points to celula principal
    aux->abaixo = aux;
    }
    return 1;
}
int InicializaLinha(TLista *lista, int i){
    Apontador aux;
    int next;
    aux = lista->principal;
    for (next = 0; next < i; ++next){
        aux->abaixo = (Apontador) malloc(sizeof(TCelula)); //Abaixo points to nova celula
        aux = aux->abaixo;                       //Ultimo points to nova celula
        aux->linha = -1;                                   //Valor da linha é o mesmo de aux
        aux->coluna = 0;
        aux->abaixo = lista->principal;             //Abaixo(NC) points to celula principal
        aux->direita = aux;
    }
    return 1;
}
int InicializaMatriz(TLista *lista){
    //Criação da célula cabeça principal
    lista->principal = (Apontador) malloc(sizeof(TCelula));   //Inicializa célula cabeça Principal
    lista->principal->direita = lista->principal;
    lista->principal->abaixo = lista->principal;
    lista->principal->linha = -1;                          //Define célula principal (linha -1 por convenção)
    lista->principal->coluna = -1;                         //Define célula principal (coluna -1 por convenção)

    return 1;
}

void ImprimeMatrizC(TLista *lista, int j){
    Apontador aux;
    int next;
    aux = lista->principal->direita;
    for(next = 0; next < j; ++next){
        printf("%d\n", aux->linha);
        printf("%d\n", aux->coluna);
        printf("\n");
        aux = aux->direita;
    }
}

void ImprimeMatrizL(TLista *lista, int i){
    Apontador aux;
    int next;
    aux = lista->principal;
    for(next = 0; next < i+1; ++next){
        printf("%d\n", aux->linha);
        printf("%d\n", aux->coluna);
        printf("\n");
        aux = aux->abaixo;
    }
}

void InsereMatriz(TLista *lista, int i, int j, int coluna, int linha){
    Apontador newcel;
    Apontador aux;
    int next;
    newcel = (Apontador)malloc(sizeof(TCelula));
    newcel->linha = linha;
    newcel->coluna = coluna;
    aux = lista->principal->direita;
    //percorre coluna
    for(next = 0; next < newcel->coluna; next++){
        aux = aux->direita;
    }
    while(linha > aux->abaixo->linha && aux->abaixo->linha != 0){
        aux = aux->abaixo;
    }
    newcel->abaixo = aux->abaixo;
    aux->abaixo = newcel;

    aux = lista->principal->abaixo;
    //percorre linha
    for(next = 0; next < newcel->linha; next++){
        aux = aux->abaixo;
    }
    while(coluna > aux->direita->coluna && aux->direita->coluna != 0){
        aux = aux->direita;
    }
    newcel->direita = aux->direita;
    aux->direita = newcel;
}

void ImprimeMatriz(TLista *lista, int linha){
    Apontador aux;
    aux = lista->principal->abaixo;
    printf("OK\n");
    printf("%d\n", aux->linha);
    printf("%d\n", aux->coluna);
    while (aux->linha == -1 && aux->coluna == -1){
        printf("ok\n");
        aux = aux->direita;
        if(aux->linha == -1 && aux->coluna == 0){
            printf("\n");
            aux = aux->abaixo->direita;
        }else{
        }

    }

}
