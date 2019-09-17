#include "TAD_MatEsparca.h"
int InicializaLinha(TCelula *celula, TLista *lista, int i){
    for (int aux = 0; aux < i; ++aux){
        lista->Ultimo->direita = (Apontador) sizeof(TCelula); //Direita points to nova celula
        lista->Ultimo = lista->Ultimo->direita;               //Ultimo points to nova celula
        lista->Ultimo->direita = lista->Primeiro->direita;    //Direita(NC) points to celula principal
        lista->Ultimo->coluna = aux;                          //Valor da coluna é o mesmo de aux
    }
    return 1;
}
int InicializaColuna(TCelula *celula, TLista *lista, int j){
    for (int aux = 0; aux < j; ++aux){
        lista->Ultimo->abaixo = (Apontador) sizeof(TCelula); //Abaixo points to nova celula
        lista->Ultimo = lista->Ultimo->abaixo;               //Ultimo points to nova celula
        lista->Ultimo->abaixo = lista->Primeiro->abaixo;     //Abaixo(NC) points to celula principal
        lista->Ultimo->linha = aux;                          //Valor da linha é o mesmo de aux
    }
    return 1;
}
int InicializaMatriz(TCelula *celula, TLista *lista, int  i, int j){

    //Criação da célula cabeça principal
    lista->Primeiro = (Apontador) sizeof(TCelula);           //Inicializa célula cabeça Principal
    lista->Ultimo = lista->Primeiro;                         //Ultimo aponta para Primeiro (própria célula)
    lista->Primeiro->direita = lista->Ultimo;                //Direita aponta para Ultimo  (própria célula)
    lista->Primeiro->abaixo = lista->Ultimo;                 //Abaixo aponta para Ultimo   (própria célula)
    celula->linha = -1;                                      //Define célula principal (linha -1 por convenção)
    celula->coluna = -1;                                     //Define célula principal (coluna -1 por convenção)
    celula->valor = 0;                                       //Valor da célula (nulo) já que se trata de célula cabeça

    //Células cabeça criadas a partir da principal de acordo com o número de linhas e colunas

    //Linhas
    InicializaLinha(&celula, &lista, i);

    //Colunas
    InicializaColuna(&celula, &lista, j);

    return 1;
}