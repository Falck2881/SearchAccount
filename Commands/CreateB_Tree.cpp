#include "CreateB_Tree.h"
#include "StructureData/BuilderBalancedTree.h"

CreateB_Tree::CreateB_Tree(const QCheckBox* const buttonChoice,
                           std::shared_ptr<ManagerBuilders> subject):buttonChoice(buttonChoice),
                                                                     subject(subject)
{
}

void CreateB_Tree::execute()
{
    if(buttonChoice->isChecked())
        subject->addMethodBuilding(std::make_unique<BuilderBalancedTree>("B_Tree",5));
}
