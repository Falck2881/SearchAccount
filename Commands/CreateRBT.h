#ifndef CREATERBT_H
#define CREATERBT_H

#include "ManagerLinkerCommand.h"

class CreateRBT: public ManagerLinkerCommand
{
    Q_OBJECT

    public:
        explicit CreateRBT(const QCheckBox* const button,
                           std::shared_ptr<ManagerBuilders> subject);
    private:
        const QCheckBox* const buttonChoice;
        std::shared_ptr<ManagerBuilders> subject;
    private slots:
        virtual void execute() final;
};

#endif // CREATERBT_H
