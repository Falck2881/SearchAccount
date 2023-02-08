#ifndef HIDEWINCOMMAND_H
#define HIDEWINCOMMAND_H

#include "ManagerLinkerCommand.h"

class HideWinCommand: public ManagerLinkerCommand
{
    Q_OBJECT

    public:
        explicit HideWinCommand(Window* const window);
    private:
        Window* const window;
    private slots:
        virtual void execute() final;
};

#endif // HIDEWINCOMMAND_H
