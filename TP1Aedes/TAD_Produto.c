#include "TAD_Produto.h"

int InicializaProd(TLisprod *lisprod){
    lisprod->Primeiro = (Apontadorp)malloc(sizeof(TCelprod));
    lisprod->Ultimo = lisprod->Primeiro;
    lisprod->Ultimo->prox = NULL;
}
int ListaVprod(TLisprod *lisprod){
    return  (lisprod->Primeiro == lisprod->Ultimo);
}
int Insere(TLisprod *lisprod, TProdutos *produtos){
    lisprod->Ultimo->prox = (Apontadorp)malloc(sizeof(TCelprod));
    lisprod->Ultimo = lisprod->Ultimo->prox;
    lisprod->Ultimo->produtos = *produtos;
    lisprod->Ultimo->prox = NULL;
    lisprod->qtdprod += lisprod->Ultimo->produtos.qtdproduto;

    return (lisprod->qtdprod);
}