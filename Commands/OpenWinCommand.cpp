#include "OpenWinCommand.h"

OpenWinCommand::OpenWinCommand(Window* const window):window{window}
{

}

void OpenWinCommand::execute()
{
    if(window != nullptr){
        window->open();
    }
}
