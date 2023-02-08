#ifndef LOADINGCOMMAND_H
#define LOADINGCOMMAND_H

#include "Stream/XmlStreamRead.h"
#include "StructureData/Account.h"
#include "Observers/ManagerBuilders.h"
#include "ManagerLinkerCommand.h"
#include <QVector>
#include <QProgressBar>

class LoadingCommand:public ManagerLinkerCommand
{
    Q_OBJECT

    public:
        explicit LoadingCommand(std::shared_ptr<ManagerBuilders> managerBuilders,
                                QProgressBar* const progressBar);
    public slots:
        virtual void execute() final;
    private:
        QVector<QVector<Account>> initialization();
        QList<QString> createListFiles();
        QVector<Account> readBlockData(std::shared_ptr<QFile> file);
        std::shared_ptr<ManagerBuilders> managerBuilders;
        QProgressBar* const progressLoading;
};
#endif // LOADINGCOMMAND_H
