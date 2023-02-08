#ifndef MANAGERLINKERCOMMAND_H
#define MANAGERLINKERCOMMAND_H

#include <QCheckBox>
#include "Commands.h"
#include "Windows/Window.h"
#include "Observers/ManagerBuilders.h"

class ManagerLinkerCommand: public Commands
{
    Q_OBJECT

    public:
        ManagerLinkerCommand(){}
        void append(std::unique_ptr<ManagerLinkerCommand> command);
    public slots:
        void execute() override;
    private:
        QList<std::shared_ptr<ManagerLinkerCommand>> commands;
};

#endif // MANAGERLINKERCOMMAND_H
