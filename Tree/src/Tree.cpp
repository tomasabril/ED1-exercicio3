#include <iostream>
#include "../include/Tree.h"

using namespace std;

Tree::Tree()
{
    topo = new No;
    profundidade = 0;
    qnt = 0;
}

void Tree::inserir(int valor)
{
    No * no = new No;
    if(qnt == 0) {
        no->dado = valor;
        no->fDir = NULL;
        no->fEsq = NULL;
        no->pai  = NULL;
        topo = no;
        qnt++;
    } else {
        No * tmp = new No;
        tmp = topo;
        while(1) {
            if(valor == tmp->dado) {
                cout << "\n esse valor já existe na arvore! \n";
                break;
            } else {
                if(valor < tmp->dado && tmp->fEsq == NULL) {
                    tmp->fEsq = no;
                    no->dado = valor;
                    no->fDir = NULL;
                    no->fEsq = NULL;
                    no->pai  = tmp;
                    qnt++;
                    break;
                } else if(valor > tmp->dado && tmp->fDir == NULL) {
                    tmp->fDir = no;
                    no->dado = valor;
                    no->fDir = NULL;
                    no->fEsq = NULL;
                    no->pai  = tmp;
                    qnt++;
                    break;
                }
                else if(valor < tmp->dado) {
                    tmp = tmp->fEsq;
                } else if(valor > tmp->dado) {
                    tmp = tmp->fDir;
                }
            }
        }
    }
}

void Tree::remover(int valor)
{
    // busca do nó a ser removido
    No *tmp = new No;
    tmp = topo;
    while(1) {
        if(valor < tmp->dado) {
            if(tmp->fEsq != NULL) {
                tmp = tmp->fEsq;
            } else {
                cout << "\n valor nao encontrado. ";
                break;
            }

        } else if(valor > tmp->dado) {

            if(tmp = tmp->fDir != NULL) {
                tmp = tmp->fDir;
            } else {
                cout << "\n valor nao encontrado. ";
                break;
            }
        } else if(valor == tmp->dado) {
            // tmp é o nó a ser removido
            break;
        }

    }
    No * aRemover = new No;
    aRemover = tmp;

    // o nó é uma folha e nao tem filhos
    if( ((aRemover->pai)->fDir)!= NULL ){}
    (aRemover->pai)->

    // o nó tem um filho apenas


    // o nó tem dois filhos

}

void Tree::apresentar()
{

}

int  Tree::lerProfundidade()
{
}

