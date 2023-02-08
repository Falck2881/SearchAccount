#ifndef AUTHORIZATIONLINKER_H
#define AUTHORIZATIONLINKER_H

#include <QObject>
#include <memory>
#include <utility>

class AuthorizationLinker: public QObject
{
    Q_OBJECT

    public:
        AuthorizationLinker(){}
        virtual ~AuthorizationLinker(){}
        void append(std::unique_ptr<AuthorizationLinker> command);
    public slots:
        void execute();
    protected slots:
        virtual bool executePartImplementation(){return true;}
    signals:
        void next();
    private:
        bool authorization();
        QList<std::shared_ptr<AuthorizationLinker>> commands;
};

#endif // AUTHORIZATIONLINKER_H
