#include "BuilderBalancedTree.h"

uint64_t fixSize(BalancedTree* tree);
void fixHeight(BalancedTree* const tree);
uint64_t fixChecksum(BalancedTree* const tree);
uint64_t calculateMediumHeightCurrentTree(BalancedTree* const tree);
uint64_t calculatePathFromRootToEachVertex(BalancedTree* const tree, uint64_t lvlVertex);

BuilderBalancedTree::BuilderBalancedTree(const QString name, qsizetype coefficient):BuilderTree(this,name),
                                                                                    coefficient(coefficient),
                                                                                    minNumberData(coefficient),
                                                                                    minNumberDescendants(coefficient+1),
                                                                                    tamporaryData(nullptr)
{

}

Tree* BuilderBalancedTree::createNewTree(QVector<Account> arrayAccountUser)
{
    BalancedTree* tree{new BalancedTree(coefficient)};

    foreach(Account account,arrayAccountUser)
        insertNewData(account,tree);

    return tree;
}

void BuilderBalancedTree::insertNewData(Account& newAccount, BalancedTree*& tree)
{
    if(tree->isTerminalVertex())
    {
        if(tree->notMaximumSizeData())
            tree->setData(newAccount);
        else{
            findIntermediateDataInNode(newAccount,tree);
            tree = createFirstRootVertex(tree);
            fixCharacteristicsTree(tree);
        }
        return;
    }
    else{
        findNodeForInsertNewData(newAccount,tree);
        tryInsertTamporaryDataInCurrentNode(tree);
    }
    tree = reconstruction(tree);
    fixCharacteristicsTree(tree);
}

void BuilderBalancedTree::findIntermediateDataInNode(Account& newAccount, BalancedTree*& tree)
{
    auto less{[](Account firstAcc, Account secondAcc)
        {
            return firstAcc.key() < secondAcc.key();
        }};
    QVector<Account>data{tree->dataUser};
    data.push_back(newAccount);
    std::sort(data.begin(), data.end(),less);
    copyData = data.at(data.size()/2);
    tamporaryData = &copyData;
    data.removeAt(data.size()/2);
    tree->dataUser = std::move(data);
}

BalancedTree* BuilderBalancedTree::createFirstRootVertex(BalancedTree* rootNode)
{
    const int leftAndRightDescendant{2};
    BalancedTree* newRootNode = new BalancedTree(coefficient);
    newRootNode->setData(*tamporaryData);
    deleteIntermediateData();

    for(int i=0; i < leftAndRightDescendant; ++i)
    {
        newRootNode->descendants.push_back(new BalancedTree(coefficient));
        for(int iteration=0; iteration < minNumberData && !rootNode->dataUser.empty(); ++iteration){
            newRootNode->descendants.at(i)->setData(rootNode->dataUser.first());
            rootNode->dataUser.removeFirst();
        }
    }
    delete rootNode;
    return newRootNode;
}

void BuilderBalancedTree::findNodeForInsertNewData(Account& newAccount, BalancedTree*& currentNode)
{
    auto less{[](Account firstAcc, Account secondAcc)
        {
            return firstAcc.key() < secondAcc.key();
        }};
    QVector<Account> data{currentNode->dataUser};
    data.push_back(newAccount);
    std::sort(data.begin(), data.end(),less);
    int64_t numberChildBranch{data.indexOf(newAccount)};

    insertNewData(newAccount,currentNode->descendants[numberChildBranch], currentNode);
}

void BuilderBalancedTree::insertNewData(Account& newAccount, BalancedTree*& currentNode, BalancedTree*& parentNode)
{
    if(currentNode->isTerminalVertex()){
        insert(newAccount,currentNode,parentNode);
        return;
    }
    else{
        findNodeForInsertNewData(newAccount,currentNode);
        tryInsertTamporaryDataInCurrentNode(currentNode);
    }
    currentNode = reconstruction(currentNode,parentNode);
    fixCharacteristicsTree(currentNode);
}

void BuilderBalancedTree::insert(Account& newAccount, BalancedTree *&currentNode, BalancedTree *&parentNode)
{
    if(currentNode->notMaximumSizeData())
        currentNode->setData(newAccount);
    else if(parentNode->notMaximumNumberDescendants())
    {
        findIntermediateDataInNode(newAccount,currentNode);
        insertNewTerminalNode(currentNode,parentNode);
        fixChecksum(currentNode);
    }
}

int64_t findIndexForInsertNewNode(BalancedTree*& parentNode, Account *&tamporaryData)
{
    auto less{[](Account firstAcc, Account secondAcc)
        {
            return firstAcc.key() < secondAcc.key();
        }};
    QVector<Account> data{parentNode->dataUser};
    data.push_back(*tamporaryData);
    std::sort(data.begin(),data.end(),less);
    return data.indexOf(*tamporaryData);
}

BalancedTree* movePieceDataInNewNode(BalancedTree*& currentNode, uint64_t coefficient)
{
    BalancedTree* newNode{new BalancedTree(coefficient)};
    int64_t quantityIteration{currentNode->dataUser.size()/2};
    for(int64_t iteration = 0; iteration < quantityIteration; ++iteration){
        newNode->setData(currentNode->dataUser.last());
        currentNode->dataUser.removeLast();
    }
    return newNode;
}

void BuilderBalancedTree::insertNewTerminalNode(BalancedTree*& currentNode, BalancedTree*& parentNode)
{
    int64_t index{findIndexForInsertNewNode(parentNode,tamporaryData)};
    BalancedTree* newTerminalNode{movePieceDataInNewNode(currentNode,coefficient)};
    parentNode->descendants.insert(index+1,newTerminalNode);
}

void BuilderBalancedTree::tryInsertTamporaryDataInCurrentNode(BalancedTree *&currentNode)
{
    if(tamporaryData != nullptr)
    {
        if(currentNode->notMaximumSizeData()){
            currentNode->setData(*tamporaryData);
            deleteIntermediateData();
        }
        else
            findIntermediateDataInNode(*tamporaryData,currentNode);
    }
}

void BuilderBalancedTree::deleteIntermediateData()
{
    tamporaryData = nullptr;
}

BalancedTree* BuilderBalancedTree::reconstruction(BalancedTree* currentNode, BalancedTree *parentNode)
{
    if(isRequiredCreateNewRootNode(currentNode,parentNode))
        currentNode = createNewRootVertex(currentNode);
    else if(isRequiredCreateNewDescendant(currentNode,parentNode)){
        createNewDescendant(currentNode,parentNode);
        fixChecksum(currentNode);
        fixSize(currentNode);
    }
    return currentNode;
}

BalancedTree* BuilderBalancedTree::createNewRootVertex(BalancedTree* currentNode)
{
    const int leftAndRightDescendant{2};
    BalancedTree* newRootVertex{new BalancedTree(coefficient)};
    newRootVertex->setData(*tamporaryData);
    deleteIntermediateData();

    for(int i = 0; i < leftAndRightDescendant; ++i)
    {
        newRootVertex->descendants.push_back(new BalancedTree(coefficient));
        for(int j = 0; j < minNumberDescendants; ++j){
            transferingDataAndDescendantsFromOldRootVertexInNewDescendant(newRootVertex->descendants.at(i), currentNode);
            fixChecksum(newRootVertex->descendants.at(i));
            fixSize(newRootVertex->descendants.at(i));
        }
    }
    delete currentNode;
    return newRootVertex;
}

void BuilderBalancedTree::transferingDataAndDescendantsFromOldRootVertexInNewDescendant(BalancedTree *newDescendent,
                                                                                        BalancedTree *currentNode)
{
    if(newDescendent->dataUser.size() != minNumberData && newDescendent->descendants.size() != minNumberDescendants){
        newDescendent->setData(currentNode->dataUser.first());
        currentNode->dataUser.removeFirst();
        newDescendent->descendants.push_back(currentNode->descendants.first());
        newDescendent->changeHeight(currentNode->descendants.first()->height());
        currentNode->descendants.removeFirst();
    }
    else if(newDescendent->descendants.size() != minNumberDescendants){
        newDescendent->descendants.push_back(currentNode->descendants.first());
        newDescendent->changeHeight(currentNode->descendants.first()->height());
        currentNode->descendants.removeFirst();
    }
}

void BuilderBalancedTree::createNewDescendant(BalancedTree *&currentNode, BalancedTree *&parentNode)
{
    int64_t index{findIndexForInsertNewNode(parentNode,tamporaryData)};
    BalancedTree* newDescendant(new BalancedTree(coefficient));
    for(qsizetype i = 0; i < minNumberDescendants; ++i){
        transferingDataAndDescendantsFromCurrentNodeInNewDescendant(newDescendant, currentNode);
        fixChecksum(newDescendant);
        fixSize(newDescendant);
    }
    parentNode->descendants.insert(index+1,newDescendant);
}

void BuilderBalancedTree::transferingDataAndDescendantsFromCurrentNodeInNewDescendant(BalancedTree *newDescendant,
                                                                                      BalancedTree *currentNode)
{
    if(newDescendant->dataUser.size() != minNumberData && newDescendant->descendants.size() != minNumberDescendants)
    {
        newDescendant->setDataInBegin(currentNode->dataUser.last());
        currentNode->dataUser.removeLast();
        newDescendant->descendants.push_front(currentNode->descendants.last());
        newDescendant->changeHeight(currentNode->descendants.last()->height());
        currentNode->descendants.removeLast();
    }
    else if (newDescendant->descendants.size() != minNumberDescendants)
    {
        newDescendant->descendants.push_front(currentNode->descendants.last());
        newDescendant->changeHeight(currentNode->descendants.last()->height());
        currentNode->descendants.removeLast();
    }
}

bool BuilderBalancedTree::isRequiredCreateNewRootNode(BalancedTree*& currentNode, BalancedTree*& parentNode) const
{
    return parentNode == nullptr &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}

bool BuilderBalancedTree::isRequiredCreateNewDescendant(BalancedTree*& currentNode,BalancedTree *&parentNode) const
{
    return parentNode != nullptr &&
           parentNode->notMaximumNumberDescendants() &&
           currentNode->maximumSizeData() &&
           currentNode->maximumNumberDescendants() ?true:false;
}

void BuilderBalancedTree::fixCharacteristicsTree(BalancedTree* const tree)
{
    fixSize(tree);
    fixHeight(tree);
    fixChecksum(tree);
    tree->changeMediumHeight(calculateMediumHeightCurrentTree(tree));
}

uint64_t fixSize(BalancedTree* tree)
{ 
    if(tree->descendants.size() != 0){
        uint64_t numberVertex = 0;
        foreach(auto descendant, tree->descendants)
            numberVertex+=descendant->sizeVertex();

        tree->changeSizeVertex(numberVertex);
    }

    return 0;
}

void fixHeight(BalancedTree*  const tree)
{
   tree->changeHeight(tree->descendants.at(0)->height());
}

uint64_t fixChecksum(BalancedTree* tree)
{
    uint64_t newCheckSum = 0;
    if(tree->descendants.size() != 0){
        uint64_t newCheckSum = tree->checksum();
        foreach(auto descendant, tree->descendants)
            newCheckSum+=descendant->checksum();
        tree->changeCheckSum(newCheckSum);
    }
    else if(tree->descendants.size() == 0){
        foreach(auto account, tree->dataUser)
            newCheckSum+=account.registrationNumber();
        tree->changeCheckSum(newCheckSum);
    }
    return 0;
}

uint64_t calculateMediumHeightCurrentTree(BalancedTree*  const tree)
{
    return calculatePathFromRootToEachVertex(tree,1) / tree->sizeVertex();
}

uint64_t calculatePathFromRootToEachVertex(BalancedTree* const tree, uint64_t lvlVertex)
{
    uint64_t allPathFromRootToEachVertex = lvlVertex;
    if(tree->descendants.size() != 0){
        foreach(auto descendant,tree->descendants)
            allPathFromRootToEachVertex+=calculatePathFromRootToEachVertex(descendant,lvlVertex+1);
    }
    return allPathFromRootToEachVertex;
}
