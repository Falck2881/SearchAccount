#ifndef COMMANDS_H
#define COMMANDS_H

#include <utility>
#include <memory>
#include <QObject>
#include <QList>
#include "Warnings/Warning.h"

class Commands: public QObject
{
    Q_OBJECT

    public:
        virtual ~Commands(){}
    public slots:
        virtual void execute() = 0;
    signals:
        void next();
        void error();
    protected:
        Commands(){}
};
#endif // COMMANDS_H
