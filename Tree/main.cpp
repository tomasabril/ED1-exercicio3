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
    Tree tree;
    tree.inserir(6);
    return 0;
}
