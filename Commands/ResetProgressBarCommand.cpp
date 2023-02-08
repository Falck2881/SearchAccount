#include "ResetProgressBarCommand.h"

ResetProgressBarCommand::ResetProgressBarCommand(QProgressBar* const progressBar):progressBar{progressBar}
{
}

void ResetProgressBarCommand::execute()
{
    progressBar->setValue(0);
}
