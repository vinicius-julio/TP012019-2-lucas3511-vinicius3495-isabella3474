#ifndef TP1AEDES_TAD_MATESPARCA_H
#define TP1AEDES_TAD_MATESPARCA_H

typedef struct Celula *Apontador;

typedef struct{
    double valor;
}TItem;

typedef struct Celula{
    Apontador direita, abaixo;
    int linha, coluna;
    TItem item;
}TCelula;

typedef struct{
    Apontador Alocal, Alocac, principal;
}TLista;

int InicializaMatriz(TLista *lista); //Inicializa matriz completa
int InicializaLinha(TLista *lista, int i); //Inicializa linha da matriz
int InicializaColuna(TLista *lista, int j); //Inicializa coluna da matriz
int LeMatriz();
void InsereMatriz(TLista *lista, TCelula *celula, int i, int j, int coluna, int linha, double valor);
void ImprimeMatrizC(TLista *lista, int j);
void ImprimeMatrizL(TLista *lista, int i);
void ImprimeMatriz(TLista *lista, int linha);

#endif //TP1AEDES_TAD_MATESPARCA_H
