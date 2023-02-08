#ifndef BUILDERBALANCEDTREE_H
#define BUILDERBALANCEDTREE_H

#include "BuilderTree.h"
#include "BalancedTree.h"

class BuilderBalancedTree: public BuilderTree
{
    public:
        BuilderBalancedTree(const QString name, qsizetype coefficient);
        virtual Tree* createNewTree(QVector<Account> arrayAccountUser) final;
    private:
        void fixCharacteristicsTree(BalancedTree* const tree);
        void insertNewData(Account& account,BalancedTree*& currentNode);
        void insertNewData(Account& account, BalancedTree*& currentNode, BalancedTree*& parentNode);
        void insert(Account& account, BalancedTree*& currentNode, BalancedTree*& parentNode);
        void tryInsertTamporaryDataInCurrentNode(BalancedTree*& currentNode);
        BalancedTree* reconstruction(BalancedTree* currentNode, BalancedTree* parentNode = nullptr);
        void findIntermediateDataInNode(Account& account,BalancedTree*& currentNode);
        void findNodeForInsertNewData(Account& account,BalancedTree*& currentNode);
        void deleteIntermediateData();
        BalancedTree* createFirstRootVertex(BalancedTree* rootNode);
        BalancedTree* createNewRootVertex(BalancedTree* currentNode);
        void insertNewTerminalNode(BalancedTree*& currentNode, BalancedTree*& parentNode);
        void createNewDescendant(BalancedTree*& currentNode, BalancedTree*&parentNode);
        void transferingDataAndDescendantsFromOldRootVertexInNewDescendant(BalancedTree* newDescendant,
                                                                           BalancedTree* currentNode);
        void transferingDataAndDescendantsFromCurrentNodeInNewDescendant(BalancedTree* newDescendant,
                                                                         BalancedTree* currentNode);
        bool isRequiredCreateNewRootNode(BalancedTree*& currentNode, BalancedTree*& parentNode) const;
        bool isRequiredCreateNewDescendant(BalancedTree*& currentNode, BalancedTree*& parentNode) const;
        qsizetype coefficient;
        qsizetype minNumberData;
        qsizetype minNumberDescendants;
        Account* tamporaryData;
        Account copyData;
};

#endif // BUILDERBALANCEDTREE_H
