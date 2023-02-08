#include "OffCheckedButtonsCommand.h"


OffCheckedButtonsCommand::OffCheckedButtonsCommand(QList<QAbstractButton*> listButtons):listButtons{listButtons}
{
}

void OffCheckedButtonsCommand::execute()
{
    if(!listButtons.isEmpty())
        offCheckedAllButtons();

}

void OffCheckedButtonsCommand::offCheckedAllButtons()
{
    foreach(auto button, listButtons)
        button->setChecked(false);
}

