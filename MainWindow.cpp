#include "MainWindow.h"
#include "Windows/WindowUser.h"
#include "Windows/WindowChoice.h"
#include "Windows/WindowLoad.h"
#include "Windows/WindowExamples.h"
#include "Windows/WindowStatistics.h"
#include "Windows/WindowDisplay.h"
#include "Commands/OpenWinCommand.h"
#include "Commands/HideWinCommand.h"
#include "Commands/IDCommand.h"
#include "Commands/AuthenticationCommand.h"
#include "Commands/OffCheckedButtonsCommand.h"
#include "ui_MainWindow.h"
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow():Window(this),
                         authorization{std::make_unique<AuthorizationLinker>()},
                         nextInWindowChoice{std::make_unique<ManagerLinkerCommand>()},
                         subject{std::make_shared<ManagerBuilders>()},
                         winUser{std::make_unique<WindowUser>()},
                         winChoose{std::make_unique<WindowChoice>(this,subject)},
                         winHelpID{std::make_unique<WindowExamples>()},
                         winStatistics{std::make_unique<WindowStatistics>(subject)},
                         winDisplayAcc{std::make_unique<WindowDisplay>(subject)},
                         ui{new Ui::MainWindow()}
{
    ui->setupUi(this);
    createCommands();
    setPropertyInput();
    setConnection();
}

void MainWindow::createCommands()
{
    addCommandsInManagerCommandForPerformAuthorization();
    addCommandsInManagerCommandForSwitchOnWindowChoice();
}

void MainWindow::addCommandsInManagerCommandForPerformAuthorization()
{
    auto id{std::make_unique<IDCommand>(ui->idLine)};
    authorization->append(std::move(id));
    auto authentication{std::make_unique<AuthenticationCommand>(subject,ui->idLine)};
    authorization->append(std::move(authentication));
}

void MainWindow::addCommandsInManagerCommandForSwitchOnWindowChoice()
{
    auto hideWin{std::make_unique<HideWinCommand>(this)};
    nextInWindowChoice->append(std::move(hideWin));
    auto openWin{std::make_unique<OpenWinCommand>(winChoose.get())};
    nextInWindowChoice->append(std::move(openWin));
}

void MainWindow::setPropertyInput()
{
    createValidator();
    setValidator();
}

void MainWindow::createValidator()
{
    QRegularExpression regExpID(QString("[^ -/:-№]{1,5}"));
    valID = std::make_unique<QRegularExpressionValidator>(regExpID, this);
}

void MainWindow::setValidator()
{
    ui->idLine->setValidator(valID.get());
}

void MainWindow::setConnection()
{
    connect(ui->hellpButton, &QPushButton::pressed, winHelpID.get(), &Window::open);
    connect(ui->loginButton, &QPushButton::pressed, authorization.get(), &AuthorizationLinker::execute);
    connect(authorization.get(), &AuthorizationLinker::next, winUser.get(), &Window::open);
    connect(ui->statisticsButton, &QPushButton::pressed, winStatistics.get(), &Window::open);
    connect(ui->downloadButton, &QPushButton::pressed, nextInWindowChoice.get(), &ManagerLinkerCommand::execute);
    connect(ui->displayAccButton, &QPushButton::clicked, winDisplayAcc.get(), &Window::open);
}

MainWindow::~MainWindow()
{
    delete ui;
}
