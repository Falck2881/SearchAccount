#include "ManagerChoice.h"
#include <QDebug>

ManagerChoice::ManagerChoice(QList<QCheckBox*> buttonsChoice):buttonsChoice{buttonsChoice},
                                                              firstChoice{nullptr},
                                                              secondChoice{nullptr}
{

}

void ManagerChoice::changedChoice(bool checked)
{
   if(findButtonChoice(checked)){
        disableNotSelectedButtons();
        if(isFinaleChoice()){
            firstChoice = nullptr;
            secondChoice = nullptr;
            emit next();
        }
   }
}

bool ManagerChoice::findButtonChoice(bool checked)
{
    bool value{false};

    foreach(auto button, buttonsChoice)
    {
        if(button->isChecked() == checked)
        {
            if(firstChoice == nullptr){
                firstChoice = button;
                value = true;
                break;
            }
            else if(secondChoice == nullptr){
                secondChoice = button;
                value = true;
                break;
            }
        }

    }

    return value;
}

bool ManagerChoice::isFinaleChoice() const
{
    return firstChoice != nullptr && secondChoice != nullptr ?true:false;
}

void ManagerChoice::disableNotSelectedButtons()
{
    if(isFinaleChoice())
    {
        foreach(auto button, buttonsChoice)
        {
            if(!button->isChecked())
                button->setEnabled(false);
        }
    }
}

void ManagerChoice::enableButtons()
{
    foreach(auto button, buttonsChoice)
    {
        if(!button->isEnabled())
            button->setEnabled(true);
    }
}
