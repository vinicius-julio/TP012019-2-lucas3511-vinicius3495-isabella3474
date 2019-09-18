#include "TAD_MatEsparca.h"
int InicializaColuna(TLista *lista, int j) {
    int aux;
    for (aux = 0; aux < j; aux++){
    lista->Ultimoc->direita = (Apontador) malloc(sizeof(TCelula)); //Direita points to nova celula
    lista->Ultimoc = lista->Ultimoc->direita;                       //Ultimo points to nova celula
    lista->Ultimoc->linha = 0;                                   //Valor da coluna é o mesmo de aux
    lista->Ultimoc->coluna = -1;
    lista->Ultimoc->item.valor = 0;
    lista->Ultimoc->direita = lista->Primeiroc;            //Direita(NC) points to celula principal
    }
    return 1;
}
int InicializaLinha(TLista *lista, int i){
    int aux;
    for (aux = 0; aux < i; ++aux){
        lista->Ultimol->abaixo = (Apontador) malloc(sizeof(TCelula)); //Abaixo points to nova celula
        lista->Ultimol = lista->Ultimol->abaixo;                       //Ultimo points to nova celula
        lista->Ultimol->linha = -1;                                   //Valor da linha é o mesmo de aux
        lista->Ultimol->coluna = 0;
        lista->Ultimol->item.valor = 0;
        lista->Ultimol->abaixo = lista->Primeirol;             //Abaixo(NC) points to celula principal
    }
    return 1;
}
int InicializaMatriz(TLista *lista){
    //Criação da célula cabeça principal
    lista->Primeirol = (Apontador) malloc(sizeof(TCelula));   //Inicializa célula cabeça Principal
    lista->Ultimol = lista->Primeirol;                         //Ultimo aponta para Primeiro (própria célula)
    lista->Ultimol->direita = lista->Primeirol;                //Direita aponta para Ultimo  (própria célula)
    lista->Ultimol->abaixo = lista->Ultimol;                 //Abaixo aponta para Ultimo   (própria célula)
    lista->Ultimol->linha = -1;                          //Define célula principal (linha -1 por convenção)
    lista->Ultimol->coluna = -1;                         //Define célula principal (coluna -1 por convenção)
    lista->Ultimol->item.valor = 0;                           //Valor da célula (nulo) já que se trata de célula cabeça
    lista->Primeiroc = lista->Primeirol;
    lista->Ultimoc = lista->Ultimol;

    return 1;
}

void ImprimeMatrizC(TLista *lista, int j){
    Apontador aux;
    int next;
    aux = lista->Primeiroc->direita;
    for(next = 0; next < j; ++next){
        printf("%d\n", aux->linha);
        printf("%d\n", aux->coluna);
        printf("%f\n", aux->item.valor);
        printf("\n");
        aux = aux->direita;
    }
}

void ImprimeMatrizL(TLista *lista, int i){
    Apontador aux;
    int next;
    aux = lista->Primeirol->abaixo;
    for(next = 0; next < i; ++next){
        printf("%d\n", aux->linha);
        printf("%d\n", aux->coluna);
        printf("%f\n", aux->item.valor);
        printf("\n");
        aux = aux->abaixo;
    }
}
