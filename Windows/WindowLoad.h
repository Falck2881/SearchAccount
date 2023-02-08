#ifndef WINDOWLOAD_H
#define WINDOWLOAD_H

#include <QVector>
#include "Window.h"
#include "Observers/ManagerBuilders.h"
#include "Commands/ManagerLinkerCommand.h"

namespace Ui {
class WindowLoading;
}

class WindowLoading: public Window
{
    Q_OBJECT

    public:
        explicit WindowLoading(Window* const winMain, std::shared_ptr<ManagerBuilders> subject);
        ~WindowLoading();
    private:
        void addCommandsInStartDownload(std::shared_ptr<ManagerBuilders> subject);
        void addCommandsInBackInMainWindow();
        virtual void setConnection() final;
        Ui::WindowLoading* ui;
        std::unique_ptr<ManagerLinkerCommand> startDownload;
        std::unique_ptr<ManagerLinkerCommand> backInMainWindow;
        Window* const winMain;
};

#endif // WINDOWLOAD_H
