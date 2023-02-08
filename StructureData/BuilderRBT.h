#ifndef BUILDERRBT_H
#define BUILDERRBT_H

#include "BuilderTree.h"

class BuilderRBT: public BuilderTree
{
    public:
        explicit BuilderRBT(const QString name);
    private:
        virtual Tree* createNewTree(QVector<Account> arrayAccountUser) final;
        uint16_t generateIndex(uint16_t rangeNumbers);
};
#endif // BUILDERRBT_H
