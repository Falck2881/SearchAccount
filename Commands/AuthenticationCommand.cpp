#include "AuthenticationCommand.h"
#include "Stream/XmlStreamRead.h"
#include "Warnings/Warning.h"
#include <QDebug>

AuthenticationCommand::AuthenticationCommand(std::shared_ptr<ManagerBuilders> subject,
                                             const QLineEdit* const stringInput):
                                             stringInput{stringInput},currentTree(nullptr)
{
    subject->append(this);
}

bool AuthenticationCommand::executePartImplementation()
{
    bool resultExecute;
    if(checkReadinessToAuthentication()){
       resultExecute = authentication();
    }
    else{
        resultExecute = false;
    }

    return resultExecute;
}

bool AuthenticationCommand::authentication()
{
    bool resultExecuteAuthentication;
    try{
        QString key = stringInput->text();
        currentTree->search(key.toUInt());
        resultExecuteAuthentication = true;
    }catch(Warning* warning){
        warning->show();
        resultExecuteAuthentication = false;
    }

    return resultExecuteAuthentication;
}

bool AuthenticationCommand::checkReadinessToAuthentication()
{
    bool resultChecking;
    try {
        checkStructureData();
        checkDataInFile();
        resultChecking = true;
    }  catch (Warning* warning) {
        warning->show();
        resultChecking = false;
    }

    return resultChecking;
}

void AuthenticationCommand::checkStructureData()
{
    if(currentTree == nullptr)
        throw new Warning("Please, Download Data!");
}


void AuthenticationCommand::checkDataInFile()
{
    std::shared_ptr<QFile> file{std::make_shared<QFile>()};
    QList<QString> listNameFile;
    listNameFile << ":/DataUser/Accounts1.xml" << ":/DataUser/Accounts2.xml" <<
                    ":/DataUser/Accounts3.xml" <<":/DataUser/Accounts4.xml" << ":/DataUser/Accounts5.xml";

    foreach(auto& nameFile, listNameFile)
    {
        file->setFileName(nameFile);
        checkAvailabilityNextBlockDataInFile(file);
        file->close();
    }
}

void AuthenticationCommand::checkAvailabilityNextBlockDataInFile(std::shared_ptr<QFile> file)
{
    XmlStreamRead streamRead(file);

    while(streamRead.isNotEndRootElement())
    {
        if(streamRead.nameElement() != QString("foreign_names"))
            throw new Warning("Data in File absent...");
        else
            break;
    }
}

void AuthenticationCommand::update(ManagerBuilders* subject)
{
    currentTree = subject->getReadyTree();
}
