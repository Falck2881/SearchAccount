#ifndef AUTHENTICATIONCOMMAND_H
#define AUTHENTICATIONCOMMAND_H

#include "AuthorizationLinker.h"
#include "Observers/ManagerBuilders.h"
#include <QLineEdit>

class AuthenticationCommand: public AuthorizationLinker, Observers
{
    Q_OBJECT

    public:
        explicit AuthenticationCommand(std::shared_ptr<ManagerBuilders> subject,
                                       const QLineEdit* const stringInput);
    private slots:
        virtual bool executePartImplementation() final;

    private:
        virtual void update(ManagerBuilders* subject) final;
        bool authentication();
        bool checkReadinessToAuthentication();
        void checkStructureData();
        void checkDataInFile();
        void checkAvailabilityNextBlockDataInFile(std::shared_ptr<QFile> file);
        const QLineEdit* const stringInput;
        Tree* currentTree;
};
#endif // AUTHENTICATIONCOMMAND_H
