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

void InsereMatriz(TLista *lista, int i, int j, int coluna, int linha,TProdutos *produtos){
    Apontador newcel;
    Apontador aux;
    int next;
    newcel = (Apontador)malloc(sizeof(TCelula));
    newcel->linha = linha;
    newcel->coluna = coluna;
    InicializaProd(&newcel->lisprod);
    Insere(&newcel->lisprod, &produtos);
    aux = lista->principal->direita;

    //percorre coluna
    for(next = 1; next < coluna; next++){
        aux = aux->direita;
    }
    while(coluna >= aux->abaixo->coluna && aux->coluna < aux->abaixo->coluna){
        if(linha == aux->abaixo->linha && aux->abaixo->coluna == coluna) {
            aux->abaixo->lisprod = newcel->lisprod;
            free(newcel);
            return;
        }
        aux = aux->abaixo;
    }
    newcel->abaixo = aux->abaixo;
    aux->abaixo = newcel;

    aux = lista->principal->abaixo;
    //percorre linha

    for(next = 1; next < linha; next++){
        aux = aux->abaixo;
    }
    while(linha >= aux->direita->linha && aux->linha< aux->direita->linha){
        aux = aux->direita;
    }
    newcel->direita = aux->direita;
    aux->direita = newcel;
}

void ImprimeMatriz(TLista *lista, TLisprod *lisprod){
    Apontador aux;
    aux = lista->principal->abaixo;
    Apontadorp pAux;
    pAux = lisprod->Primeiro->prox;

    while (aux->coluna != -1){

        aux = aux->direita;

        if(aux->linha == -1){
            printf("\n");
            aux = aux->abaixo;
        }else {
            while (pAux != NULL){
                printf("%d %s", &pAux->produtos.qtdproduto, pAux->produtos.datacompra);
                pAux = pAux->prox;
            }
        }

    }
}