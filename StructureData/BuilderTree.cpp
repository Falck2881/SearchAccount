#include "BuilderTree.h"

void fixSize(BinaryTree* const tree);
void fixHeight(BinaryTree* const tree);
void fixChecksum(BinaryTree* const tree);
bool vertex(BinaryTree* const tree);
uint64_t height(BinaryTree* const tree);
bool isExistsChecksum(BinaryTree* const tree);
uint64_t calculateMediumHeightCurrentTree(BinaryTree* const tree);
uint64_t calculatePathFromRootToEachVertex(BinaryTree* const tree, uint64_t lvlVertex);

BuilderTree::BuilderTree(BuilderTree* const descendantBuilderTree, QString nameDescendantBuilderTree):
                        nameConcreteBuilderTree(nameDescendantBuilderTree),
                        concreteBuilderTree{descendantBuilderTree}
{
}

void BuilderTree::initializationConstruction(QVector<QVector<Account>> arraysAccountsUser)
{

    if(isOldCharacteristics()){
        build(arraysAccountsUser);
    }
    else{
        removeAllCharacteristicsTrees();
        build(arraysAccountsUser);
    }
}

bool BuilderTree::isOldCharacteristics()
{
    return characteristicsTrees.isEmpty()?true:false;
}

void BuilderTree::build(QVector<QVector<Account>> arraysAccountsUser)
{
    for(uint8_t index = 0; index != arraysAccountsUser.size(); ++index){
        trees.push_back(concreteBuilderTree->createNewTree(arraysAccountsUser.at(index)));
        addCharacteristicsFromCurrentTree(trees.at(index));
    }
}

void BuilderTree::removeAllCharacteristicsTrees()
{
   while(!characteristicsTrees.isEmpty() && !trees.isEmpty()){
       characteristicsTrees.removeFirst();
       trees.last()->removeAll();
       trees.removeLast();
   }
}

void BuilderTree::createNewNode(Account account, BinaryTree*& tree)
{
    if(tree == nullptr)
    {
        tree = new BinaryTree();
        tree->setData(account);
        return;
    }
    else if(account.key() < tree->key())
        createNewNode(account, tree->leftChildNode);
    else if(account.key() > tree->key())
        createNewNode(account, tree->rightChildNode);

    fixCharacteristicsTree(tree);
}

QString BuilderTree::nameBuilder()
{
    return nameConcreteBuilderTree;
}

Tree*& BuilderTree::getReadyTree()
{
    return trees.last();
}

QVector<QString> BuilderTree::arrayCharacteristicsTree(uint8_t index)
{
    return characteristicsTrees.at(index);
}

void BuilderTree::fixCharacteristicsTree(BinaryTree* const tree)
{
    fixSize(tree);
    fixHeight(tree);
    fixChecksum(tree);
    tree->changeMediumHeight(calculateMediumHeightCurrentTree(tree));
}

void fixSize(BinaryTree* const tree)
{
    bool leftDescendant = vertex(tree->leftChildNode);
    bool rightDescendant = vertex(tree->rightChildNode);

    if(leftDescendant && rightDescendant)
        tree->changeSizeVertex(tree->leftChildNode->sizeVertex() + tree->rightChildNode->sizeVertex());
    else if(leftDescendant)
        tree->changeSizeVertex(tree->leftChildNode->sizeVertex());
    else if(rightDescendant)
        tree->changeSizeVertex(tree->rightChildNode->sizeVertex());
}

bool vertex(BinaryTree* const tree)
{
    return tree!=nullptr?true:false;
}

void fixHeight(BinaryTree* const tree)
{
    uint64_t heightLeftDescendant = height(tree->leftChildNode);
    uint64_t heightRightDescendant = height(tree->rightChildNode);

    if(heightLeftDescendant ==  heightRightDescendant)
        tree->changeHeight( heightRightDescendant);
    else if(heightLeftDescendant >  heightRightDescendant)
        tree->changeHeight(heightLeftDescendant);
    else if(heightRightDescendant > heightLeftDescendant)
        tree->changeHeight(heightRightDescendant);
}

uint64_t height(BinaryTree* tree)
{
    return tree!=nullptr?tree->height():0;
}

void fixChecksum(BinaryTree* const tree)
{
    bool leftDescendant = isExistsChecksum(tree->leftChildNode);
    bool rightDescendant = isExistsChecksum(tree->rightChildNode);
    uint64_t newChecksum = 0;

    if(leftDescendant && rightDescendant)
    {
        newChecksum = tree->checksum()+tree->leftChildNode->checksum()+tree->rightChildNode->checksum();
        tree->changeCheckSum(newChecksum);
    }
    else if(leftDescendant)
    {
        newChecksum = tree->checksum()+tree->leftChildNode->checksum();
        tree->changeCheckSum(newChecksum);
    }
    else if(rightDescendant)
    {
        newChecksum = tree->checksum()+tree->rightChildNode->checksum();
        tree->changeCheckSum(newChecksum);
    }
    else if(leftDescendant == 0 && rightDescendant == 0){
        tree->returnStartingChecksum(); // When Constructing Avl Tree
    }
}

bool isExistsChecksum(BinaryTree* const tree)
{
    return tree!=nullptr?true:false;
}

uint64_t calculateMediumHeightCurrentTree(BinaryTree* const tree)
{
    return calculatePathFromRootToEachVertex(tree,1) / tree->sizeVertex();
}

uint64_t calculatePathFromRootToEachVertex(BinaryTree* const tree, uint64_t lvlVertex)
{
    if(tree == nullptr){
        return 0;
    }
    else{
        return lvlVertex + calculatePathFromRootToEachVertex(tree->leftChildNode,lvlVertex+1)+
                calculatePathFromRootToEachVertex(tree->rightChildNode, lvlVertex+1);
    }
}

void BuilderTree::addCharacteristicsFromCurrentTree(Tree* const tree)
{
    QVector<QString> arrayCharacteristics;
    arrayCharacteristics << QString::number(tree->checksum()) <<
                            QString::number(tree->height()) <<
                            QString::number(tree->mediumHeight());
    characteristicsTrees.push_back(arrayCharacteristics);
}
