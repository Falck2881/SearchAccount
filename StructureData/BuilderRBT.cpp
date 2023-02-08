#include "BuilderRBT.h"
#include <QRandomGenerator64>

BuilderRBT::BuilderRBT(const QString name):BuilderTree(this, name)
{
}

Tree* BuilderRBT::createNewTree(QVector<Account> arrayAccountUser)
{
    uint16_t rangeNumbers = arrayAccountUser.size();
    BinaryTree* tree = nullptr;

    for(auto step = arrayAccountUser.begin(); step != arrayAccountUser.end(); ++step)
        createNewNode(arrayAccountUser.at(generateIndex(rangeNumbers)), tree);

    return tree;
}

uint16_t BuilderRBT::generateIndex(uint16_t rangeNumbers)
{
    QRandomGenerator64 randomIndex;

    return std::move(randomIndex.system()->bounded(rangeNumbers));
}
