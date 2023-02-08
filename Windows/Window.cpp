#include "Window.h"

Window::Window(Window* window):window{window}
{
}

void Window::open()
{
    window->show();
}

void Window::close()
{
    window->hide();
}
