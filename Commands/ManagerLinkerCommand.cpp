#include "ManagerLinkerCommand.h"

void ManagerLinkerCommand::append(std::unique_ptr<ManagerLinkerCommand> command)
{
    commands.push_back(std::move(command));
}

void ManagerLinkerCommand::execute()
{
    foreach(auto& command, commands){
        command->execute();
    }
}
