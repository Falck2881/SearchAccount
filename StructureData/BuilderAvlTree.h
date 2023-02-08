#ifndef BUILDERAVLTREE_H
#define BUILDERAVLTREE_H

#include "../Stream/XmlStreamRead.h"
#include "BuilderTree.h"

class BuilderAvlTree: public BuilderTree
{
    public:
        BuilderAvlTree(const QString nameBuilder);
    private:   
        virtual Tree* createNewTree(QVector<Account> arrayAccountUser) final;
        virtual void createNewNode(Account account, BinaryTree*& tree);
        void fixBalance(BinaryTree*& tree);
        int8_t calculateBalanced(BinaryTree* tree);
        uint64_t height(BinaryTree* const tree);
        BinaryTree* rotateTreeOnLeft(BinaryTree* currentNode);
        BinaryTree* rotateTreeOnRight(BinaryTree* currentNode);
};
#endif // BUILDERAVLTREE_H
