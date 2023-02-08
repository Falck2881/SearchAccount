#include "HideWinCommand.h"

HideWinCommand::HideWinCommand(Window* const window):window{window}
{

}

void HideWinCommand::execute()
{
    if(window != nullptr){
        window->close();
    }
}
