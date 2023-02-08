#ifndef CREATETWO_THREE_TREE_H
#define CREATETWO_THREE_TREE_H

#include "ManagerLinkerCommand.h"

class CreateTwo_Three_Tree: public ManagerLinkerCommand
{
    public:
        CreateTwo_Three_Tree(QCheckBox* const buttonChoice,
                             std::shared_ptr<ManagerBuilders> subject);
    private slots:
        virtual void execute() final;
    private:
        const QCheckBox* const buttonChoice;
        std::shared_ptr<ManagerBuilders> subject;
};

#endif // CREATETWO_THREE_TREE_H
