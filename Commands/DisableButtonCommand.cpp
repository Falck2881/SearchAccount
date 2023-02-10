#include "DisableButtonCommand.h"

DisableButtonCommand::DisableButtonCommand(QPushButton* const button):button{button}
{
}

void DisableButtonCommand::execute()
{
    if(button->isEnabled())
        button->setEnabled(false);
}
