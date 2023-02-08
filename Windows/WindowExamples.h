#ifndef WINDOWEXAMPLES_H
#define WINDOWEXAMPLES_H

#include "Window.h"

namespace Ui {
class WindowExamples;
}

class WindowExamples : public Window
{
    Q_OBJECT

    public:
        WindowExamples();
        ~WindowExamples();
    private:
        virtual void setConnection() final;
        Ui::WindowExamples *ui;
};

#endif // WINDOWEXAMPLES_H
