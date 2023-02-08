#include "BuilderAvlTree.h"
#include "../Stream/XmlStreamRead.h"

BuilderAvlTree::BuilderAvlTree(const QString nameBuilder):BuilderTree(this,nameBuilder)
{
}

Tree* BuilderAvlTree::createNewTree(QVector<Account> arrayAccountUser)
{
    BinaryTree* tree = nullptr;

    for(uint16_t index = 0; index != arrayAccountUser.size(); ++index)
        createNewNode(arrayAccountUser.at(index), tree);

    return tree;
}



void BuilderAvlTree::createNewNode(Account account, BinaryTree*& tree)
{
    if(tree == nullptr){
        tree = new BinaryTree();
        tree->setData(account);
        return;
    }
    else if(account.key() > tree->key())
        createNewNode(account, tree->rightChildNode);
    else if(account.key() < tree->key())
        createNewNode(account, tree->leftChildNode);

    fixCharacteristicsTree(tree);
    fixBalance(tree);
}

void BuilderAvlTree::fixBalance(BinaryTree*& tree)
{

    if(calculateBalanced(tree) == 2)
    {
        if(calculateBalanced(tree->rightChildNode) == -1)
            tree = rotateTreeOnRight(tree->rightChildNode);

        tree = rotateTreeOnLeft(tree);
    }
    else if(calculateBalanced(tree) == -2)
    {
        if(calculateBalanced(tree->leftChildNode) == 1)
            tree = rotateTreeOnLeft(tree->leftChildNode);

        tree = rotateTreeOnRight(tree);
    }
}


int8_t BuilderAvlTree::calculateBalanced(BinaryTree *tree)
{
    uint64_t heightLeftChildNode = height(tree->leftChildNode);
    uint64_t heightRightChildNode = height(tree->rightChildNode);

    return heightRightChildNode - heightLeftChildNode;
}

uint64_t BuilderAvlTree::height(BinaryTree* tree)
{
    return tree!=nullptr?tree->height():0;
}

BinaryTree* BuilderAvlTree::rotateTreeOnLeft(BinaryTree* currentNode)
{
     BinaryTree* newCurrentNode = currentNode->rightChildNode;
     currentNode->rightChildNode = newCurrentNode->leftChildNode;
     newCurrentNode->leftChildNode = currentNode;

     fixCharacteristicsTree(currentNode);
     fixCharacteristicsTree(newCurrentNode);

     return newCurrentNode;
}

BinaryTree* BuilderAvlTree::rotateTreeOnRight(BinaryTree* currentNode)
{
    BinaryTree* newCurrentNode = currentNode->leftChildNode;
    currentNode->leftChildNode = newCurrentNode->rightChildNode;
    newCurrentNode->rightChildNode = currentNode;

    fixCharacteristicsTree(currentNode);
    fixCharacteristicsTree(newCurrentNode);

    return newCurrentNode;
}
