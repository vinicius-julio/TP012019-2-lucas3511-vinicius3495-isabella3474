#ifndef TP1AEDES_TAD_MATESPARCA_H
#define TP1AEDES_TAD_MATESPARCA_H

typedef struct Celula* Apontador;

typedef struct Celula{
    Apontador *direita, *abaixo;
    int linha, coluna;
    double valor;
}TCelula;

typedef struct{
    Apontador Primeiro, Ultimo;
}TLista;

int InicializaMatriz(TCelula *celula, TLista *lista, int i, int j); //Inicializa matriz completa
int InicializaLinha(TCelula *celula, TLista *lista, int i); //Inicializa linha da matriz
int InicializaColuna(TCelula *celula, TLista *lista, int j); //Inicializa coluna da matriz
int LeMatriz();
int InsereMatriz();
int ImprimeMatriz();

#endif //TP1AEDES_TAD_MATESPARCA_H
