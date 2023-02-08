#include "EnabledButtonCommand.h"

EnabledButtonCommand::EnabledButtonCommand(QPushButton* const button):button{button}
{

}

void EnabledButtonCommand::execute()
{
    button->setEnabled(true);
}
