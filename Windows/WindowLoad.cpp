#include "WindowLoad.h"
#include "ui_WindowLoad.h"
#include "Commands/LoadingCommand.h"
#include "Commands/OpenWinCommand.h"
#include "Commands/HideWinCommand.h"
#include "Commands/LoadingCommand.h"
#include "Commands/ResetProgressBarCommand.h"
#include "Commands/OffCheckedButtonsCommand.h"
#include "Commands/EnabledButtonCommand.h"
#include "Commands/DisableButtonCommand.h"
#include <QTimer>
#include <QList>

WindowLoading::WindowLoading(Window* const winMain, std::shared_ptr<ManagerBuilders> subject):
                             Window(this),
                             ui{new Ui::WindowLoading()},
                             startDownload{std::make_unique<ManagerLinkerCommand>()},
                             backInMainWindow{std::make_unique<ManagerLinkerCommand>()},
                             winMain{winMain}

{
    ui->setupUi(this);
    addCommandsInStartDownload(subject);
    addCommandsInBackInMainWindow();
    ui->progressBar->setMaximum(500);
    setConnection();
}


void WindowLoading::addCommandsInStartDownload(std::shared_ptr<ManagerBuilders> subject)
{
    auto loading{std::make_unique<LoadingCommand>(subject, ui->progressBar)};
    startDownload->append(std::move(loading));
    auto onNextButton{std::make_unique<EnabledButtonCommand>(ui->nextButton)};
    startDownload->append(std::move(onNextButton));
    auto offStartButton{std::make_unique<DisableButtonCommand>(ui->startButton)};
    startDownload->append(std::move(offStartButton));
}

void WindowLoading::addCommandsInBackInMainWindow()
{
    auto hideWin{std::make_unique<HideWinCommand>(this)};
    backInMainWindow->append(std::move(hideWin));
    auto openWin{std::make_unique<OpenWinCommand>(winMain)};
    backInMainWindow->append(std::move(openWin));

    auto resetProgressBar{std::make_unique<ResetProgressBarCommand>(ui->progressBar)};
    backInMainWindow->append(std::move(resetProgressBar));

    auto onStartButton{std::make_unique<EnabledButtonCommand>(ui->startButton)};
    backInMainWindow->append(std::move(onStartButton));
    auto offNextButton{std::make_unique<DisableButtonCommand>(ui->nextButton)};
    backInMainWindow->append(std::move(offNextButton));
}

void WindowLoading::setConnection()
{
    connect(ui->startButton, &QPushButton::pressed, startDownload.get(), &ManagerLinkerCommand::execute);
    connect(ui->progressBar, &QProgressBar::valueChanged, ui->progressBar, &QProgressBar::setValue);
    connect(ui->nextButton, &QPushButton::pressed, backInMainWindow.get(), &ManagerLinkerCommand::execute);
}

WindowLoading::~WindowLoading()
{
    delete  ui;
}
