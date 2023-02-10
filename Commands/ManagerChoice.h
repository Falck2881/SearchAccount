#ifndef MANAGERCHOICE_H
#define MANAGERCHOICE_H

#include <QList>
#include <QCheckBox>
#include <QPushButton>
#include <QObject>

class ManagerChoice: public QObject
{
    Q_OBJECT

    public:
        ManagerChoice(QList<QCheckBox*> buttonsChoice);
    public slots:
        void changedChoice(bool active);
    signals:
        void onNext();
        void offNext();
    private:
        void changeStatusNotActiveButtonsChoice();
        void changeStatusActiveButtonsChoice();
        QList<QCheckBox*> buttonsChoice;
        uint8_t currentAmountSelectedBuilders;
        const uint8_t maxAmountSelectedBuilders;
};

#endif // MANAGERCHOICE_H
