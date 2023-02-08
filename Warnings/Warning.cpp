#include "Warning.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QIcon>

Warning::Warning(QString massage):title{"WARNING!"},
                                  massage{massage},
                                  buttonOk{std::make_unique<QPushButton>("OK!")}
{
    setPropertys();
    setLayoutWidgets();
    connections();

}

void Warning::setPropertys()
{
    this->setWindowTitle(title);
    this->setWindowIcon(QIcon(":/Image/Warning.png"));
    this->setMaximumSize(250,100);
    this->setFixedSize(250,100);
    this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
    buttonOk->setCheckable(true);
    buttonOk->setFixedSize(100,30);
}

void Warning::setLayoutWidgets()
{
    QLabel* label = new QLabel(massage,this);
    label->setAlignment(Qt::AlignHCenter);
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(label, 0, Qt::AlignVCenter);
    layout->addWidget(buttonOk.get(), 0, Qt::AlignHCenter);
    this->setLayout(layout);
}

void Warning::connections()
{
    connect(buttonOk.get(), &QPushButton::clicked, this, &Warning::confirmError);
}

void Warning::confirmError()
{
    if(isClickedOk())
    {
        this->hide();
        delete this;
    }
}

bool Warning::isClickedOk()
{
    return buttonOk->isChecked() ? true: false;
}
