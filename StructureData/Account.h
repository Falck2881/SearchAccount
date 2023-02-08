#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <QList>
#include "../Stream/XmlStreamRead.h"

class Account
{
    public:
        Account();
        uint64_t key();
        uint64_t registrationNumber();
        bool operator==(const Account& acc) const;
        bool operator<(const Account&acc) const;
        friend XmlStreamRead& operator>>(XmlStreamRead& stream, Account& account);
        friend QDataStream& operator>>(QDataStream& stream, Account& account);
        friend QDataStream& operator<<(QDataStream& stream, Account& account);
        friend QList<QString>& operator<<(QList<QString>& dataUser, Account& account);
    private:
        QString registeredEmployee;
        QString id;
        QString name;
        QString meaning;
        QString gender;
        QString origin;
        QString peoplesCount;
        QString whenPeoplesCount;
};

#endif // ACCOUNT_H
