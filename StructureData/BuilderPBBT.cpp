#include "BuilderPBBT.h"

BuilderPBBT::BuilderPBBT(const QString name):BuilderTree(this,name)
{
}

Tree* BuilderPBBT::createNewTree(QVector<Account> arrayAccountUser)
{
    BinaryTree* currentTree = nullptr;
    int64_t leftEdgeContainer = 0;
    int64_t rightEdgeContainer = arrayAccountUser.size()-1;

    int64_t index = ((leftEdgeContainer+rightEdgeContainer)/2);
    currentTree = new BinaryTree();
    currentTree->setData(arrayAccountUser.at(index));

    currentTree->leftChildNode = createNewTree(arrayAccountUser, currentTree->leftChildNode,
                                                                 leftEdgeContainer, index-1);
    currentTree->rightChildNode = createNewTree(arrayAccountUser, currentTree->rightChildNode,
                                                                  index+1, rightEdgeContainer);
    fixCharacteristicsTree(currentTree);

    return currentTree;
}

BinaryTree* BuilderPBBT::createNewTree(QVector<Account> arrayAccountUser,
                                       BinaryTree* currentTree,
                                       const int64_t leftEdgeContainer,
                                       const int64_t rightEdgeContainer)
{
    if(leftEdgeContainer > rightEdgeContainer)
        return currentTree;
    else
    {
        int64_t index = ((leftEdgeContainer+rightEdgeContainer)/2);
        currentTree = new BinaryTree();
        currentTree->setData(arrayAccountUser.at(index));
        currentTree->leftChildNode = createNewTree(arrayAccountUser, currentTree->leftChildNode,
                                                                          leftEdgeContainer, index-1);
        currentTree->rightChildNode = createNewTree(arrayAccountUser, currentTree->rightChildNode,
                                                                            index+1,rightEdgeContainer);

        fixCharacteristicsTree(currentTree);
    }
    return currentTree;
}
