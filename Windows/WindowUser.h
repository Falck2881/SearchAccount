#ifndef WINDOWUSER_H
#define WINDOWUSER_H

#include "StructureData/Account.h"
#include "Window.h"
#include <QString>

namespace Ui {
class WindowUser;
}

class WindowUser : public Window
{
    Q_OBJECT

    public:
        WindowUser();
       ~WindowUser();
    private slots:
        virtual void open() final;
    private:
        void insertDataAccountUserInTable();
        Account deserializationAccountUser();
        virtual void setConnection() final;
        Ui::WindowUser* ui;
};
#endif // WINDOWUSER_H
