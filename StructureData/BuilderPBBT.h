#ifndef BUILDERPBBT_H
#define BUILDERPBBT_H

#include "BuilderTree.h"

class BuilderPBBT: public BuilderTree
{
    public:
        explicit BuilderPBBT(const QString name);
    private:
        virtual Tree* createNewTree(QVector<Account> arrayAccountUser) final;
        BinaryTree* createNewTree(QVector<Account> arrayAccountUser, BinaryTree* tree,
                                  const int64_t leftEdgeContainer, const int64_t rightEdgeContiner);
};
#endif // BUILDERPBBT_H
