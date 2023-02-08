#include "CreateAvlTree.h"
#include "StructureData/BuilderAvlTree.h"

CreateAvlTree::CreateAvlTree(const QCheckBox* const buttonChoice, std::shared_ptr<ManagerBuilders> subject):
                             buttonChoice{buttonChoice},subject{subject}
{
}

void CreateAvlTree::execute()
{
    if(buttonChoice->isChecked())
        subject->addMethodBuilding(std::make_unique<BuilderAvlTree>("AVL Tree"));
}
