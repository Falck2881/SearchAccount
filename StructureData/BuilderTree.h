#ifndef BUILDERTREE_H
#define BUILDERTREE_H

#include "Tree.h"
#include <QList>
#include <QVector>
#include "BinaryTree.h"

class BuilderTree
{
    public:
        BuilderTree(BuilderTree* const descendantBuilderTree, const QString nameBuilder);
        virtual ~BuilderTree(){}
        Tree*& getReadyTree();
        QVector<QString> arrayCharacteristicsTree(uint8_t index);
        void initializationConstruction(QVector<QVector<Account>> arraysAccountsUser);
        QString nameBuilder();
    protected:
        virtual Tree* createNewTree(QVector<Account> arrayAccountUser) = 0;
        virtual void createNewNode(Account account, BinaryTree*& tree);
        void fixCharacteristicsTree(BinaryTree* const tree);
    private:
        bool isOldCharacteristics();
        void addCharacteristicsFromCurrentTree(Tree* const tree);
        void removeAllCharacteristicsTrees();
        void build(QVector<QVector<Account>> arraysAccountsUser);
        QString nameConcreteBuilderTree;
        BuilderTree* const concreteBuilderTree;
        QVector<QVector<QString>> characteristicsTrees;
        QVector<Tree*> trees;
};
#endif // BUILDERTREE_H
