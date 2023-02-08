#ifndef ENABLEDALLBUTTONSCHOICECOMMAND_H
#define ENABLEDALLBUTTONSCHOICECOMMAND_H

#include "ManagerLinkerCommand.h"

class EnabledAllButtonsChoiceCommand: public ManagerLinkerCommand
{
    public:
        EnabledAllButtonsChoiceCommand(QList<QAbstractButton*> listButtons);
    private slots:
        virtual void execute() final;
    private:
        void onCheckedAllButtons();
        QList<QAbstractButton*> listButtons;
};

#endif // ENABLEDALLBUTTONSCHOICECOMMAND_H
