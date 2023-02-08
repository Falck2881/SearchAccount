#ifndef CREATEAVLTREE_H
#define CREATEAVLTREE_H

#include "ManagerLinkerCommand.h"

class CreateAvlTree: public ManagerLinkerCommand
{
    public:
        CreateAvlTree(const QCheckBox* const buttonChoice,
                      std::shared_ptr<ManagerBuilders> subject);
    private:
        virtual void execute() final;
        const QCheckBox* const buttonChoice;
        std::shared_ptr<ManagerBuilders> subject;
};

#endif // CREATEAVLTREE_H
