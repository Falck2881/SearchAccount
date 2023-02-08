#ifndef DISABLEBUTTONCOMMAND_H
#define DISABLEBUTTONCOMMAND_H

#include "ManagerLinkerCommand.h"
#include <QPushButton>

class DisableButtonCommand: public ManagerLinkerCommand
{
    public:
        DisableButtonCommand(QPushButton* const button);
    private slots:
        virtual void execute() final;
    private:
        QPushButton* const button;
};

#endif // DISABLEBUTTONCOMMAND_H
