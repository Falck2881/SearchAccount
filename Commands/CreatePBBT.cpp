#include "CreatePBBT.h"
#include "StructureData/BuilderPBBT.h"

CreatePBBT::CreatePBBT(const QCheckBox* const buttonChoice, std::shared_ptr<ManagerBuilders> subject):
                       buttonChoice{buttonChoice},subject{subject}
{

}

void CreatePBBT::execute()
{
    if(buttonChoice->isChecked())
        subject->addMethodBuilding(std::make_unique<BuilderPBBT>("Perfect Balanced Binary Tree"));
}
