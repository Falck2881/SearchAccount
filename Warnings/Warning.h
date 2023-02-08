#ifndef WARNING_H
#define WARNING_H

#include <QString>
#include <QPushButton>
#include <QWidget>

class Warning: public QWidget
{
    Q_OBJECT

    public:
        Warning(QString massage = "");
    public slots:
        void confirmError();
    private:
        ~Warning(){};
        bool isClickedOk();
        void setPropertys();
        void setLayoutWidgets();
        void connections();
        QString title;
        QString massage;
        std::unique_ptr<QPushButton> buttonOk;
};

#endif // WARNING_H
