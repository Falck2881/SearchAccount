#include "ManagerChoice.h"
#include <QDebug>

ManagerChoice::ManagerChoice(QList<QCheckBox*> buttonsChoice):buttonsChoice{buttonsChoice},
                                                              currentAmountSelectedBuilders{0},
                                                              maxAmountSelectedBuilders{2}
{

}

void ManagerChoice::changedChoice(bool activeButton)
{
    if(activeButton)
    {
        ++currentAmountSelectedBuilders;
        if(currentAmountSelectedBuilders == maxAmountSelectedBuilders){
            changeStatusNotActiveButtonsChoice();
            emit onNext();
        }
    }
    else
    {
        --currentAmountSelectedBuilders;
        if(currentAmountSelectedBuilders != maxAmountSelectedBuilders){
            emit offNext();
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
