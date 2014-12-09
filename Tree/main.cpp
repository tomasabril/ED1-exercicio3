/*
Elaborar um programa que apresente o seguinte menu:
1) Inserção em árvore binária
2) Remoção em árvore binária
3) Apresentação da árvore
A árvore deve ser apresentada da seguinte forma:
Raiz: 25 FE: 20 FD: 30
Nó 20: FE: 10 FD: 23
Nó 30: FE: 28 FD: 40
Nó 10: FE: 5 FD: 15
Nó 23: FE: -1 FD: -1
Nó 28: FE: -1 FD: -1
Nó 40: FE: -1 FD: -1
Nó 5: FE: -1 FD:-1
Nó 15: FE: -1 FD: -1

*/

#include <iostream>
#include "include/Tree.h"

using namespace std;

int main()
{
    /*  // teste
    Tree tree;
    tree.inserir(15);
    tree.inserir(4);
    tree.inserir(20);
    tree.inserir(1);
    tree.inserir(16);
    tree.inserir(25);
    tree.apresentar();
    */

    int op;
    int valor;
    Tree * tree = new Tree;

    cout << " -- Arvore binaria --\n";
    while(1) {
        cout << "\n   _Menu_\n";
        cout << " 1) Insercao em arvore binaria\n";
        cout << " 2) Remocao em arvore binaria \n";
        cout << " 3) Apresentacao da arvore\n";
        cin >> op;

        switch(op) {
        case 1:
            cout << "\n digite valor para inserir: ";
            cin >> valor;
            (*tree).inserir(valor);
            break;
        case 2:
            if( (*tree).qnt > 0 ) {
                cout << "\n digite valor para remover: ";
                cin >> valor;
                (*tree).remover(valor);
            } else {
                cout << "\n arvore vazia!\n";
            }
            break;
        case 3:
            //cout << "\n quantidade " << (*tree).qnt << "\n";
            if( (*tree).qnt > 0 ) {
                (*tree).apresentar();
            } else {
                cout << "\n arvore vazia!\n";
            }
            break;
        default:
            cout << "opcao invalida\n";
        }
    }

    return 0;
}
