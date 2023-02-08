#include "DisableButtonCommand.h"

DisableButtonCommand::DisableButtonCommand(QPushButton* const button):button{button}
{
}

void DisableButtonCommand::execute()
{
    button->setEnabled(false);
}
