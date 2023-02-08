#ifndef WINDOWLOADING_H
#define WINDOWLOADING_H

#include "Window.h"
#include "Observers/ManagerBuilders.h"
#include "Commands/ManagerLinkerCommand.h"
#include "Commands/ManagerChoice.h"
#include <QCheckBox>

namespace Ui {
class WindowChoice;
}

class WindowChoice : public Window
{
    Q_OBJECT

    public:
        explicit WindowChoice(Window* const winMain, std::shared_ptr<ManagerBuilders> subject);
        ~WindowChoice();
    private:
        void createCommands();
        void createCommandManagerChoice();
        void addCommandsInManagerInitChoice();
        void createCommandsForSwitchingWindows();
        void addCommandsInBackInMainWindow();
        void addCommandsInNextInWindowLoading();
        void temporarilyDisableNotActiveButtons();
        virtual void setConnection() final;
        void createConnectionWithButtonsChoiceUser();
        void createConnectionWithMainWindow();
        void createConnectionWithWindowLoading();
        Ui::WindowChoice* ui;
        Window* const winMain;
        std::unique_ptr<Window> winLoading;
        std::shared_ptr<ManagerBuilders> subject;
        std::unique_ptr<ManagerChoice> managerChoice;
        std::unique_ptr<ManagerLinkerCommand> managerInitSelectedObj;
        std::unique_ptr<ManagerLinkerCommand> backInMainWindow;
        std::unique_ptr<ManagerLinkerCommand> nextInWindowLoading;
};

#endif // WINDOWLOADING_H