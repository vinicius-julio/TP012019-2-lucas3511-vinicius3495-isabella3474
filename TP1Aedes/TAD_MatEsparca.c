#include "TAD_MatEsparca.h"
int InicializaColuna(TLista *lista, int j) {
    int aux;
    for (aux = 0; aux < j; aux++){
    lista->Alocac->direita = (Apontador) malloc(sizeof(TCelula)); //Direita points to nova celula
    lista->Alocac = lista->Alocac->direita;                       //Ultimo points to nova celula
    lista->Alocac->linha = 0;                                   //Valor da coluna é o mesmo de aux
    lista->Alocac->coluna = -1;
    lista->Alocac->item.valor = 0;
    lista->Alocac->direita = lista->principal;            //Direita(NC) points to celula principal
    lista->Alocac->abaixo = lista->Alocac;
    }
    return 1;
}
int InicializaLinha(TLista *lista, int i){
    int aux;
    for (aux = 0; aux < i; ++aux){
        lista->Alocal->abaixo = (Apontador) malloc(sizeof(TCelula)); //Abaixo points to nova celula
        lista->Alocal = lista->Alocal->abaixo;                       //Ultimo points to nova celula
        lista->Alocal->linha = -1;                                   //Valor da linha é o mesmo de aux
        lista->Alocal->coluna = 0;
        lista->Alocal->item.valor = 0;
        lista->Alocal->abaixo = lista->principal;             //Abaixo(NC) points to celula principal
        lista->Alocal->direita = lista->Alocal;
    }
    return 1;
}
int InicializaMatriz(TLista *lista){
    //Criação da célula cabeça principal
    lista->principal = (Apontador) malloc(sizeof(TCelula));   //Inicializa célula cabeça Principal
    lista->Alocal = lista->principal;
    lista->Alocal->direita = lista->Alocal;                //Direita aponta para Ultimo  (própria célula)
    lista->Alocal->abaixo = lista->Alocal;                 //Abaixo aponta para Ultimo   (própria célula)
    lista->Alocal->linha = -1;                          //Define célula principal (linha -1 por convenção)
    lista->Alocal->coluna = -1;                         //Define célula principal (coluna -1 por convenção)
    lista->Alocal->item.valor = 0;                           //Valor da célula (nulo) já que se trata de célula cabeça
    lista->Alocac = lista->Alocal;
    lista->Alocac = lista->Alocal;

    return 1;
}

void ImprimeMatrizC(TLista *lista, int j){
    Apontador aux;
    int next;
    aux = lista->principal->direita;
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
    aux = lista->principal;
    for(next = 0; next < i+1; ++next){
        printf("%d\n", aux->linha);
        printf("%d\n", aux->coluna);
        printf("%f\n", aux->item.valor);
        printf("\n");
        aux = aux->abaixo;
    }
}

void InsereMatriz(TLista *lista, TCelula *celula, int i, int j, int coluna, int linha, double valor){
    Apontador newcel;
    Apontador aux;
    int next;
    newcel = (Apontador)malloc(sizeof(TCelula));
    newcel->linha = linha;
    newcel->coluna = coluna;
    newcel->item.valor = valor;
    aux = lista->principal->direita;
    //percorre coluna
    for(next = 1; next < coluna; next++){
        aux = aux->direita;
    }
    while(linha >= aux->abaixo->linha && aux->abaixo->coluna != -1){
        aux = aux->abaixo;
    }
    newcel->abaixo = aux->abaixo;
    aux->abaixo = newcel;

    //percorre linha
    for(next = 1; next < linha; next++){
        aux = aux->abaixo;
    }
    while(coluna >= aux->direita->coluna && aux->direita->linha != -1){
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
            printf("%lf", aux->item.valor);
        }

    }

}
