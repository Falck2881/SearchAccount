#include "EnabledAllButtonsChoiceCommand.h"

EnabledAllButtonsChoiceCommand::EnabledAllButtonsChoiceCommand(QList<QAbstractButton*> listButtons):
                                                               listButtons{listButtons}
{
}

void EnabledAllButtonsChoiceCommand::execute()
{
    if(!listButtons.isEmpty())
        onCheckedAllButtons();
}

void EnabledAllButtonsChoiceCommand::onCheckedAllButtons()
{
    foreach(auto checkedButton, listButtons)
        checkedButton->setEnabled(true);
}
