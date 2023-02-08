#include "WarningArchive.h"

WarningArchive::WarningArchive(QString massage):Warning(this, massage)
{

}

void WarningArchive::confirmErrorSignal()
{
    if(isClickedOk())
    {
        this->hide();
    }
}
