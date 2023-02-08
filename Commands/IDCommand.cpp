#include "IDCommand.h"

IDCommand::IDCommand(QLineEdit* const stringInput):stringInput{stringInput}
{
}

bool IDCommand::executePartImplementation()
{
    bool resultExecute;
    if(checkInput())
        resultExecute = true;
    else
        resultExecute = false;

    return resultExecute;
}

bool IDCommand::checkInput()
{
    bool resultChecking;
    try{
      if(stringInput->text() == ""){
           throw new Warning("Please, input ID user.");
      }
      resultChecking = true;
    }catch(Warning* const warning)
    {
        warning->show();
        resultChecking = false;
    }

    return resultChecking;
}
