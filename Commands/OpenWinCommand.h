#ifndef OPENWINCOMMAND_H
#define OPENWINCOMMAND_H

#include "ManagerLinkerCommand.h"

class OpenWinCommand: public ManagerLinkerCommand
{
    Q_OBJECT

    public:
        OpenWinCommand(Window* const window);
    private:
        Window* const window;
    private slots:
        virtual void execute() final;
};

#endif // OPENWINCOMMAND_H
