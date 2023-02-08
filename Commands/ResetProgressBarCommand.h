#ifndef RESETPROGRESSBARCOMMAND_H
#define RESETPROGRESSBARCOMMAND_H

#include "ManagerLinkerCommand.h"
#include <QProgressBar>

class ResetProgressBarCommand: public ManagerLinkerCommand
{
    public:
        ResetProgressBarCommand(QProgressBar* const progressBar);
    private slots:
        virtual void execute() final;
    private:
        QProgressBar* const progressBar;
};

#endif // RESETPROGRESSBARCOMMAND_H
