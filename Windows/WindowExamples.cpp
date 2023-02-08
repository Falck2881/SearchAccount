#include "WindowExamples.h"
#include "ui_WindowExamples.h"

WindowExamples::WindowExamples():Window(this),ui(new Ui::WindowExamples)
{
    ui->setupUi(this);
    setConnection();
}

void WindowExamples::setConnection()
{
    connect(ui->okButton, &QPushButton::pressed, this, &Window::close);
}

WindowExamples::~WindowExamples()
{
    delete ui;
}
