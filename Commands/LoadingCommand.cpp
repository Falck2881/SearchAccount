#include "LoadingCommand.h"
#include <QTimer>
LoadingCommand::LoadingCommand(std::shared_ptr<ManagerBuilders> managerBuilders,QProgressBar* const progressLoading):
                                managerBuilders{managerBuilders},progressLoading{progressLoading}
{
}

void LoadingCommand::execute()
{
    managerBuilders->initializeBuilders(initialization());
    emit next();
}

QVector<QVector<Account>> LoadingCommand::initialization()
{
    QVector<QVector<Account>> containerArrays;
    uint16_t percentageCompleted = 100;
    QList<QString> namesFiles{createListFiles()};
    std::shared_ptr<QFile> file{std::make_shared<QFile>()};

    foreach(auto& name, namesFiles)
    {
        file->setFileName(name);
        containerArrays.push_back(readBlockData(file));
        emit progressLoading->valueChanged(percentageCompleted+=100);
        file->close();
    }
    return containerArrays;
}

QList<QString> LoadingCommand::createListFiles()
{
    QList<QString> namesFiles;
    namesFiles << ":/DataUser/Accounts1.xml" << ":/DataUser/Accounts2.xml" << ":/DataUser/Accounts3.xml" <<
                    ":/DataUser/Accounts4.xml" << ":/DataUser/Accounts5.xml";
    return namesFiles;
}


QVector<Account> LoadingCommand::readBlockData(std::shared_ptr<QFile> file)
{
    XmlStreamRead streamRead(file);
    Account currentAccount;
    QVector<Account> currentArrayAccountUsers;

    while(streamRead.isNotEndRootElement())
    {
        streamRead >> currentAccount;
        currentArrayAccountUsers.push_back(currentAccount);
    }
    return currentArrayAccountUsers;
}
