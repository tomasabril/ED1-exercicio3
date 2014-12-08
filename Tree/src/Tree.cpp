#include <iostream>
#include <queue>
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
                cout << "\n esse valor ja existe na arvore! \n";
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
                } else if(valor < tmp->dado) {
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
    // busca do no a ser removido
    No *tmp = new No;
    tmp = topo;
    bool direcao;   // 0 e esquerda // 1 e direita;

    while(1) {
        if(valor < tmp->dado) {
            if(tmp->fEsq != NULL) {
                tmp = tmp->fEsq;
                direcao = 0;
            } else {
                cout << "\n valor nao encontrado. ";
                break;
            }

        } else if(valor > tmp->dado) {
            if(tmp->fDir != NULL) {
                tmp = tmp->fDir;
                direcao = 1;
            } else {
                cout << "\n valor nao encontrado. ";
                break;
            }
        } else if(valor == tmp->dado) {
            // tmp й o nу a ser removido
            break;
        }

    }
    //No * aRemover = new No;
    //aRemover = tmp;

    // o no e uma folha e nao tem filhos
    if(tmp->fDir == NULL && tmp->fEsq == NULL) {
        if(tmp->pai == NULL) {  // remover o topo
            delete tmp;
            qnt--;
        } else {
            if(direcao == 0) {
                (tmp->pai)->fEsq == NULL;
                delete tmp;
                qnt--;
            } else {
                (tmp->pai)->fDir == NULL;
                delete tmp;
                qnt--;
            }
        }

    }

    // o no tem dois filhos
    else if(tmp->fDir != NULL && tmp->fEsq != NULL) {

    }

    // o no tem um filho apenas
    else {
        if(tmp->fEsq != NULL) {
            if(direcao == 0) {
                (tmp->pai)->fEsq == tmp->fEsq;
                (tmp->fEsq)->pai == tmp->pai;
                delete tmp;
                qnt--;
            } else {
                (tmp->pai)->fDir == tmp->fEsq;
                (tmp->fEsq)->pai == tmp->pai;
                delete tmp;
                qnt--;
            }
        } else {        // tmp->fDir != NULL
            if(direcao == 0) {
                (tmp->pai)->fEsq == tmp->fDir;
                (tmp->fDir)->pai == tmp->pai;
                delete tmp;
                qnt--;
            } else {
                (tmp->pai)->fDir == tmp->fDir;
                (tmp->fDir)->pai == tmp->pai;
                delete tmp;
                qnt--;
            }
        }
    }

}

void Tree::apresentar()
{
    // por percurso por largura e extensão
    std::queue<No*> lista;
    lista.push(topo);
    cout << " Raiz: " << topo->dado
         << " FE: " << (topo->fEsq)->dado
         << " FD: " << (topo->fDir)->dado
         << "\n";
    No * tmp = new No;
    tmp=topo;
    while(!lista.empty()) {
        if(tmp->fEsq != NULL) {
            lista.push(tmp->fEsq);
            cout << " No: " << (tmp->fEsq)->dado;
            if( ((tmp->fEsq)->fEsq) != NULL ) {
                cout << " FE: " << ((tmp->fEsq)->fEsq)->dado;
            } else {
                cout << " FE: -1";
            }
            if( ((tmp->fEsq)->fDir) != NULL ) {
                cout << " FD: " << ((tmp->fEsq)->fDir)->dado;
            } else {
                cout << " FD: -1";
            }
            cout << "\n";
        }
        if(tmp->fDir != NULL) {
            lista.push(tmp->fDir);
            cout << " No: " << (tmp->fDir)->dado;
            if( ((tmp->fDir)->fEsq) != NULL) {
                cout << " FE: " << ((tmp->fDir)->fEsq)->dado;
            } else {
                cout << " FE: -1";
            }
            if( ((tmp->fDir)->fDir) != NULL ) {
                cout << " FD: " << ((tmp->fDir)->fDir)->dado;
            } else {
                cout << " FD: -1";
            }
            cout << "\n";
        }

        tmp = lista.front();
        lista.pop();
    }

    //allan
    /*cout << "raiz!" << topo->dado << "FE" << (topo->fEsq)->dado << "FD" << (topo->fDir)->dado;
    cout << "\n";
    No * no = new No;
    no = topo;
    while() {
    }*/
}
