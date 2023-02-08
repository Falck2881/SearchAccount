#ifndef OFFLISTBUTTONCOMMAND_H
#define OFFLISTBUTTONCOMMAND_H

#include "ManagerLinkerCommand.h"
#include <QAbstractButton>

class OffCheckedButtonsCommand: public ManagerLinkerCommand
{
    Q_OBJECT
    public:
        explicit OffCheckedButtonsCommand(QList<QAbstractButton*> listButtons);
    private slots:
        virtual void execute() final;
    private:
        void offCheckedAllButtons();
        QList<QAbstractButton*> listButtons;

};

#endif // OFFLISTBUTTONCOMMAND_H
