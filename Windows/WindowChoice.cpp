#include "WindowChoice.h"
#include "Windows/WindowLoad.h"
#include "Commands/CreatePBBT.h"
#include "Commands/CreateRBT.h"
#include "Commands/CreateAvlTree.h"
#include "Commands/CreateB_Tree.h"
#include "Commands/CreateTwo_Three_Tree.h"
#include "Commands/OpenWinCommand.h"
#include "Commands/HideWinCommand.h"
#include "Commands/ManagerChoice.h"
#include "Commands/EnabledButtonCommand.h"
#include "Commands/DisableButtonCommand.h"
#include "Commands/OffCheckedButtonsCommand.h"
#include "Commands/EnabledAllButtonsChoiceCommand.h"
#include "ui_WindowChoice.h"

WindowChoice::WindowChoice(Window* const winMain, std::shared_ptr<ManagerBuilders> subject):
    Window(this),
    ui{new Ui::WindowChoice()},winMain{winMain},
    winLoading{std::make_unique<WindowLoading>(winMain,subject)},subject(subject),
    managerInitSelectedObj{std::make_unique<ManagerLinkerCommand>()},
    backInMainWindow{std::make_unique<ManagerLinkerCommand>()},
    nextInWindowLoading{std::make_unique<ManagerLinkerCommand>()}
{
    ui->setupUi(this);
    createCommands();
    temporarilyDisableNotActiveButtons();
    setConnection();
}

void WindowChoice::createCommands()
{
    createCommandManagerChoice();
    addCommandsInManagerInitChoice();
    createCommandsForSwitchingWindows();
}

void WindowChoice::createCommandManagerChoice()
{
    QList<QCheckBox*> buttonsChoice{ui->choosePBBT,ui->chooseRBT,ui->chooseAvlTree,ui->chooseBTree,ui->chooseTwoThreeTree};
    managerChoice = std::make_unique<ManagerChoice>(buttonsChoice);
}

void WindowChoice::addCommandsInManagerInitChoice()
{
    auto createPBBT{std::make_unique<CreatePBBT>(ui->choosePBBT, subject)};
    managerInitSelectedObj->append(std::move(createPBBT));
    auto createRBT{std::make_unique<CreateRBT>(ui->chooseRBT, subject)};
    managerInitSelectedObj->append(std::move(createRBT));
    auto createAvlTree{std::make_unique<CreateAvlTree>(ui->chooseAvlTree, subject)};
    managerInitSelectedObj->append(std::move(createAvlTree));
    auto createBTree{std::make_unique<CreateB_Tree>(ui->chooseBTree, subject)};
    managerInitSelectedObj->append(std::move(createBTree));
    auto createTwoThreeTree{std::make_unique<CreateTwo_Three_Tree>(ui->chooseTwoThreeTree,subject)};
    managerInitSelectedObj->append(std::move(createTwoThreeTree));
    auto onButtonNext{std::make_unique<EnabledButtonCommand>(ui->nextButton)};
    managerInitSelectedObj->append(std::move(onButtonNext));

}

void WindowChoice::createCommandsForSwitchingWindows()
{
    addCommandsInBackInMainWindow();
    addCommandsInNextInWindowLoading();
}

void WindowChoice::addCommandsInBackInMainWindow()
{
    auto offNextButton{std::make_unique<DisableButtonCommand>(ui->nextButton)};
    backInMainWindow->append(std::move(offNextButton));

    QList<QAbstractButton*> buttonsChoice{ui->choosePBBT,ui->chooseRBT,ui->chooseAvlTree};
    auto offCheckedAllQCheckBox{std::make_unique<OffCheckedButtonsCommand>(buttonsChoice)};
    backInMainWindow->append(std::move(offCheckedAllQCheckBox));
    auto enabledAllButtonsChoice{std::make_unique<EnabledAllButtonsChoiceCommand>(buttonsChoice)};
    backInMainWindow->append(std::move(enabledAllButtonsChoice));
    auto hideWin = std::make_unique<HideWinCommand>(this);
    backInMainWindow->append(std::move(hideWin));
    auto openWin = std::make_unique<OpenWinCommand>(winMain);
    backInMainWindow->append(std::move(openWin));
}

void WindowChoice::addCommandsInNextInWindowLoading()
{
    auto offNextButton{std::make_unique<DisableButtonCommand>(ui->nextButton)};
    nextInWindowLoading->append(std::move(offNextButton));

    QList<QAbstractButton*> buttonsChoice{ui->choosePBBT,ui->chooseRBT,
                                          ui->chooseAvlTree, ui->chooseBTree,
                                          ui->chooseTwoThreeTree};
    auto offCheckedAllQCheckBox{std::make_unique<OffCheckedButtonsCommand>(buttonsChoice)};
    nextInWindowLoading->append(std::move(offCheckedAllQCheckBox));
    auto enabledAllButtonsChoice{std::make_unique<EnabledAllButtonsChoiceCommand>(buttonsChoice)};
    nextInWindowLoading->append(std::move(enabledAllButtonsChoice));

    auto hideWin{std::make_unique<HideWinCommand>(this)};
    nextInWindowLoading->append(std::move(hideWin));
    auto openWin{std::make_unique<OpenWinCommand>(winLoading.get())};
    nextInWindowLoading->append(std::move(openWin));
}

void WindowChoice::temporarilyDisableNotActiveButtons()
{
    ui->nextButton->setEnabled(false);
}

void WindowChoice::setConnection()
{
    createConnectionWithButtonsChoiceUser();
    createConnectionWithMainWindow();
    createConnectionWithWindowLoading();
}

void WindowChoice::createConnectionWithButtonsChoiceUser()
{
    QList<QCheckBox*> buttonsChoice{ui->chooseRBT,ui->choosePBBT,ui->chooseAvlTree,
                                    ui->chooseBTree,ui->chooseTwoThreeTree};
    foreach(auto buttonChoice, buttonsChoice)
        connect(buttonChoice, &QCheckBox::toggled, managerChoice.get(), &ManagerChoice::fixateChoice);

    connect(managerChoice.get(), &ManagerChoice::next, managerInitSelectedObj.get(), &ManagerLinkerCommand::execute);
}

void WindowChoice::createConnectionWithMainWindow()
{
    connect(ui->backButton, &QPushButton::pressed, backInMainWindow.get(), &ManagerLinkerCommand::execute);
}

void WindowChoice::createConnectionWithWindowLoading()
{
    QObject::connect(ui->nextButton, &QPushButton::pressed, nextInWindowLoading.get(), &ManagerLinkerCommand::execute);
}

WindowChoice::~WindowChoice()
{
    delete ui;
}
