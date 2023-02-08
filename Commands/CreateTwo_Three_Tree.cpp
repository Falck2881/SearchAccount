#include "CreateTwo_Three_Tree.h"
#include "StructureData/BuilderBalancedTree.h"

CreateTwo_Three_Tree::CreateTwo_Three_Tree
(QCheckBox* const buttonChoice,std::shared_ptr<ManagerBuilders> subject):buttonChoice(buttonChoice),
                                                                         subject(subject)
{

}

void CreateTwo_Three_Tree::execute()
{
    if(buttonChoice->isChecked())
        subject->addMethodBuilding(std::make_unique<BuilderBalancedTree>("Two_Three_Tree",1));
}
