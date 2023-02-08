#include "ManagerBuilders.h"

ManagerBuilders::ManagerBuilders()
{
}

void ManagerBuilders::addMethodBuilding(std::unique_ptr<BuilderTree> newMethodBuilder)
{
    if(firstBuilder == nullptr)
        firstBuilder = std::move(newMethodBuilder);
    else if(secondBuilder == nullptr)
        secondBuilder = std::move(newMethodBuilder);
}

void ManagerBuilders::append(Observers *observer)
{
    listObservers.push_back(observer);
}

void ManagerBuilders::initializeBuilders(const QVector<QVector<Account>> containerData)
{
    firstBuilder->initializationConstruction(containerData);
    secondBuilder->initializationConstruction(containerData);

    notifyAllObservers();
}

void ManagerBuilders::notifyAllObservers()
{
    foreach(auto observer, listObservers)
        observer->update(this);
}

Tree*& ManagerBuilders::getReadyTree()
{
    if(firstBuilder->getReadyTree()->height() < secondBuilder->getReadyTree()->height())
       return firstBuilder->getReadyTree();
    else if(secondBuilder->getReadyTree()->height() < firstBuilder->getReadyTree()->height())
       return secondBuilder->getReadyTree();
}


BuilderTree* ManagerBuilders::getFirstBuilder()
{
    return firstBuilder.get();
}

BuilderTree* ManagerBuilders::getSecondBuilder()
{
    return secondBuilder.get();
}
