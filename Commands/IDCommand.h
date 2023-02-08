#ifndef IDCOMMAND_H
#define IDCOMMAND_H

#include "Warnings/Warning.h"
#include "AuthorizationLinker.h"
#include <QLineEdit>

class IDCommand: public AuthorizationLinker
{
    Q_OBJECT

    public:
        explicit IDCommand(QLineEdit* const stringInput);
    signals:
        void clear();
    private slots:
        virtual bool executePartImplementation() final;
    private:
        void connection();
        bool checkInput();
        QLineEdit* const stringInput;
};
#endif // IDCOMMAND_H
