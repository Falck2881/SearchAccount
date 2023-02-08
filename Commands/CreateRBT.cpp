#include "CreateRBT.h"
#include "StructureData/BuilderRBT.h"

CreateRBT::CreateRBT(const QCheckBox* const buttonChoice, std::shared_ptr<ManagerBuilders> subject):
                    buttonChoice{buttonChoice},subject{subject}
{

}

void CreateRBT::execute()
{
    if(buttonChoice->isChecked())
        subject->addMethodBuilding(std::make_unique<BuilderRBT>("Random Binary Tree"));
}
