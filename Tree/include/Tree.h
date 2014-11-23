#ifndef TREE_H
#define TREE_H

struct No{
    int dado;
    //No * pai;
    No * fDir;
    No * fEsq;
    No * pai;
};

class Tree
{
    public:
        No * topo;
        int profundidade;
        int qnt;


        Tree();
        void inserir(int valor);
        void remover(int valor);
        void apresentar();
        int  lerProfundidade();
    protected:
    private:
};

#endif // TREE_H
