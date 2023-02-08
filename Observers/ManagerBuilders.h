#ifndef MANAGERBUILDERS_H
#define MANAGERBUILDERS_H

#include "StructureData/BuilderTree.h"
#include "Observers.h"
#include <QList>

class ManagerBuilders
{
    public:
        ManagerBuilders();
        void append(Observers* observer);
        void addMethodBuilding(std::unique_ptr<BuilderTree> newMethodBuilder);
        void initializeBuilders(const QVector<QVector<Account>> containerData);
        Tree*& getReadyTree();
        BuilderTree* getFirstBuilder();
        BuilderTree* getSecondBuilder();
    private:
        void notifyAllObservers();
        QList<Observers*> listObservers;
        std::unique_ptr<BuilderTree> firstBuilder;
        std::unique_ptr<BuilderTree> secondBuilder;
};
#endif // MANAGERBUILDERS_H
