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
    if(qnt == 0)
    {
        no->dado = valor;
        no->fDir = NULL;
        no->fEsq = NULL;
        topo = no;
    }
    else
    {
        No * tmp = new No;
        tmp = topo;
        while(1)
        {
            if(valor == tmp->dado)
            {
                cout << "\n esse valor já existe na arvore! \n";
                qnt--;
                break;
            }
            else if(tmp->fDir == NULL && tmp->fEsq == NULL)
            {
                if(valor < tmp->dado)
                {
                    tmp->fEsq = no;
                    no->dado = valor;
                    no->fDir = NULL;
                    no->fEsq = NULL;
                }
                else
                {
                    tmp->fDir = no;
                    no->dado = valor;
                    no->fDir = NULL;
                    no->fEsq = NULL;
                }
                break;
            }
            else if(valor < tmp->dado)
            {
                tmp = tmp->fEsq;
            }
            else if(valor > tmp->dado)
            {
                tmp = tmp->fDir;
            }
        }
    }
    cout << topo->dado;
    qnt++;
}

void Tree::remover()
{
}

void Tree::apresentar()
{

}

int  Tree::lerProfundidade()
{
}

