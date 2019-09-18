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
    Apontador Primeirol, Ultimol;
    Apontador Primeiroc, Ultimoc;
}TLista;

int InicializaMatriz(TLista *lista); //Inicializa matriz completa
int InicializaLinha(TLista *lista, int i); //Inicializa linha da matriz
int InicializaColuna(TLista *lista, int j); //Inicializa coluna da matriz
int LeMatriz();
int InsereMatriz();
void ImprimeMatrizC(TLista *lista, int j);
void ImprimeMatrizL(TLista *lista, int i);

#endif //TP1AEDES_TAD_MATESPARCA_H
