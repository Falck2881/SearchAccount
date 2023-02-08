#include "WindowUser.h"
#include "ui_WindowUser.h"
#include <QTableWidgetItem>
#include "StructureData/Account.h"


WindowUser::WindowUser():Window(this),ui(new Ui::WindowUser())
{
    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(true);
    setConnection();
}

void WindowUser::setConnection()
{
    connect(ui->pushButton, &QPushButton::clicked, this, &Window::close);
}

void WindowUser::open()
{
    insertDataAccountUserInTable();
    this->show();
}

void WindowUser::insertDataAccountUserInTable()
{
    QList<QString> dataUser;
    Account account = deserializationAccountUser();
    dataUser << account;

    for(int i = 0; i != dataUser.size(); ++i)
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString(dataUser.at(i))));
}

Account WindowUser::deserializationAccountUser()
{
    Account account;
    QFile file(QString("dataUser.dat"));
    if(file.open(QIODevice::ReadOnly)){
        QDataStream stream(&file);
        stream >> account;
        file.close();
    }
    else{
        qDebug() << "Warning! FILE NOT OPEN!";
    }
    return account;
}

WindowUser::~WindowUser()
{
    delete ui;
}
