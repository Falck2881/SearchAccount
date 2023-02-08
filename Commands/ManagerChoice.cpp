#include "ManagerChoice.h"
#include <QDebug>

ManagerChoice::ManagerChoice(QList<QCheckBox*> buttonsChoice):buttonsChoice{buttonsChoice},
                                                              currentAmountSelectedBuilders{0},
                                                              maxAmountSelectedBuilders{2}
{

}

void ManagerChoice::fixateChoice(bool activeButton)
{
    if(activeButton)
    {
        ++currentAmountSelectedBuilders;
        if(currentAmountSelectedBuilders == maxAmountSelectedBuilders){
            changeStatusNotActiveButtonsChoice();
            emit next();
        }
    }
    else
    {
        --currentAmountSelectedBuilders;
        if(currentAmountSelectedBuilders != maxAmountSelectedBuilders){
            changeStatusActiveButtonsChoice();
        }
    }
}

void ManagerChoice::changeStatusNotActiveButtonsChoice()
{
    foreach(auto buttonChoice, buttonsChoice)
    {
        if(!buttonChoice->isChecked())
        {
            if(!buttonChoice->isChecked())
                buttonChoice->setEnabled(false);
            else
                qDebug() << "Warning! - There is no logical operator -> '!' ";
        }
    }
}

void ManagerChoice::changeStatusActiveButtonsChoice()
{
    foreach(auto buttonChoice, buttonsChoice)
    {
        if(buttonChoice->isChecked())
        {
            if(buttonChoice->isChecked())
                buttonChoice->setEnabled(true);
            else
                qDebug() << "Warning! - Return result should be 'true' ";
        }
    }
}
