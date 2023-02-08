#include "AuthorizationLinker.h"

void AuthorizationLinker::append(std::unique_ptr<AuthorizationLinker> command)
{
    commands.push_back(std::move(command));
}

void AuthorizationLinker::execute()
{
    if(authorization())
        emit next();
}

bool AuthorizationLinker::authorization()
{
    bool resultExecuteAuthorization = true;
    foreach(auto command, commands)
    {
        if(command->executePartImplementation())
            resultExecuteAuthorization = true;
        else{
            resultExecuteAuthorization = false;
            break;
        }
    }
    return resultExecuteAuthorization;
}
