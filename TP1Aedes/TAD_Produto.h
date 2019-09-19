#ifndef TP1AEDES_TAD_PRODUTO_H
#define TP1AEDES_TAD_PRODUTO_H

typedef struct celula *Apontadorp;

typedef struct {
    char datacompra[10];
    int qtdproduto;
}TProdutos;

typedef struct celula{
    TProdutos produtos;
    Apontadorp prox;
}TCelprod;

typedef struct{
    Apontadorp Primeiro, Ultimo;
    int qtdprod;
}TLisprod;

int InicializaProd(TLisprod *lisprod);
int ListaVprod(TLisprod *lisprod);
int Insere(TLisprod *lisprod, TProdutos *produtos);

#endif //TP1AEDES_TAD_PRODUTO_H
