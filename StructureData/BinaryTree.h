#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "Tree.h"

class BinaryTree: public Tree
{
    public:
        BinaryTree();
        uint64_t key();
        virtual void setData(Account account) final;
        void returnStartingChecksum();
        BinaryTree* leftChildNode;
        BinaryTree* rightChildNode;
    private:
        virtual void removeAll() final;
        void removeAll(BinaryTree* node);
        virtual void treeTraversal(QTableWidget *table) final;
        virtual void search(uint64_t key) final;
        void search(uint64_t key, BinaryTree* node);
        void insertAllDataInTable();
        void insertAllDataInTable(uint64_t& row, BinaryTree* tree);
        void extractDataFromNodeInTable(uint64_t& row, BinaryTree* tree);
        Account dataUser;
};

#endif // BINARYTREE_H
