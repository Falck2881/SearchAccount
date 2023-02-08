#ifndef CREATEPBBT_H
#define CREATEPBBT_H

#include "ManagerLinkerCommand.h"

class CreatePBBT: public ManagerLinkerCommand
{
    Q_OBJECT

    public:
        explicit CreatePBBT(const QCheckBox* const buttonChoice,
                            std::shared_ptr<ManagerBuilders> subject);
    private:
        const QCheckBox* const buttonChoice;
        std::shared_ptr<ManagerBuilders> subject;
    private slots:
        virtual void execute() final;
};

#endif // CREATEPBBT_H
