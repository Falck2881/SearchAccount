#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Windows/PropertyInput.h"
#include "Windows/Window.h"
#include "Commands/ManagerLinkerCommand.h"
#include "Observers/ManagerBuilders.h"
#include "Commands/AuthorizationLinker.h"
#include <QValidator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public Window, PropertyInput
{
    Q_OBJECT

    public:
        MainWindow();
        ~MainWindow();
    private:
        void createWindows();
        void createCommands();
        void addCommandsInManagerCommandForPerformAuthorization();
        void addCommandsInManagerCommandForSwitchOnWindowChoice();
        virtual void setPropertyInput() final;
        virtual void createValidator() final;
        virtual void setValidator() final;
        virtual void setConnection() final;
        std::unique_ptr<QValidator> valID;
        std::unique_ptr<AuthorizationLinker> authorization;
        std::unique_ptr<ManagerLinkerCommand> nextInWindowChoice;
        std::shared_ptr<ManagerBuilders> subject;
        std::unique_ptr<Window> winUser;
        std::unique_ptr<Window> winChoose;
        std::unique_ptr<Window> winHelpID;
        std::unique_ptr<Window> winStatistics;
        std::unique_ptr<Window> winDisplayAcc;
        Ui::MainWindow* ui;
};
#endif // MAINWINDOW_H
