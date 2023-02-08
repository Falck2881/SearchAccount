#ifndef CREATEB_TREE_H
#define CREATEB_TREE_H

#include "ManagerLinkerCommand.h"

class CreateB_Tree: public ManagerLinkerCommand
{
    public:
        explicit CreateB_Tree(const QCheckBox* const buttonChoice,
                              std::shared_ptr<ManagerBuilders> subject);
    private:
        const QCheckBox* const buttonChoice;
        std::shared_ptr<ManagerBuilders> subject;
    private slots:
        virtual void execute() final;

};

#endif // CREATEB_TREE_H
