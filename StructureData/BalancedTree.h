#ifndef BALANCEDTREE_H
#define BALANCEDTREE_H

#include "Account.h"
#include <QVector>
#include <memory>
#include <cstdint>
#include "Tree.h"

class BalancedTree: public Tree
{
    public:
        BalancedTree(const qsizetype coefficient);
        virtual void search(uint64_t key) final;
        virtual void setData(Account data) final;
        void setDataInBegin(Account data);
        bool isTerminalVertex() const ;
        bool notMaximumSizeData() const;
        bool notMaximumNumberDescendants() const;
        bool maximumNumberDescendants() const;
        bool maximumSizeData() const;
        QVector<BalancedTree*> descendants;
        QVector<Account> dataUser;
    private:
        virtual void removeAll() final;
        void removeAll(BalancedTree* currentNode);
        virtual void treeTraversal(QTableWidget *table) final;
        void search(uint64_t key, BalancedTree* node);
        void insertAllDataInTable(uint64_t row = 0);
        void insertAllDataInTable(uint64_t& row, BalancedTree* tree);
        void extractDataFromNodeInTable(uint64_t& row, Account currentAccount);
        void setMaximumSizeStoredData();
        void setMaximumSizePossibleDescendants();
        qsizetype maxSizeStoredData;
        qsizetype maxSizeDecendants;
};

#endif // BALANCEDTREE_H
