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
        void changedChoice(bool checked);
    signals:
        void next();
    private:
        bool isFinaleChoice() const;
        bool findButtonChoice(bool checked);
        void disableNotSelectedButtons();
        void enableButtons();
        QList<QCheckBox*> buttonsChoice;
        QCheckBox* firstChoice;
        QCheckBox* secondChoice;
};

#endif // MANAGERCHOICE_H
