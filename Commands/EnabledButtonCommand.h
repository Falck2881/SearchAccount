#ifndef ENABLEDBUTTONCOMMAND_H
#define ENABLEDBUTTONCOMMAND_H

#include "ManagerLinkerCommand.h"
#include <QPushButton>

class EnabledButtonCommand: public ManagerLinkerCommand
{
    public:
        EnabledButtonCommand(QPushButton* const button);
    private slots:
        virtual void execute() final;
    private:
        QPushButton* const button;
};

#endif // ENABLEDBUTTONCOMMAND_H
