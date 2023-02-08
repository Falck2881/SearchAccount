#include "Account.h"

Account::Account()
{

}

uint64_t Account::key()
{
    return id.toUInt();
}

uint64_t Account::registrationNumber()
{
    return registeredEmployee.toUInt();
}

bool Account::operator==(const Account &acc) const
{
    return this->id.toUInt() == acc.id.toUInt();
}

bool Account::operator<(const Account &acc) const
{
    return this->id.toUInt() < acc.id.toUInt();
}

XmlStreamRead& operator>>(XmlStreamRead& stream, Account& account)
{
    QByteArray array = stream.readBlockData();
    QDataStream dataStream(&array, QIODevice::ReadOnly);

    dataStream >> account.registeredEmployee >> account.id >> account.name >> account.meaning >> account.gender >>
    account.origin >> account.peoplesCount >> account.whenPeoplesCount;
    return stream;
}

QDataStream& operator<<(QDataStream& stream, Account& account)
{
    stream << account.registeredEmployee << account.id << account.name << account.meaning << account.gender <<
              account.origin << account.peoplesCount << account.whenPeoplesCount;
    return stream;
}

QDataStream& operator>>(QDataStream& stream, Account& account)
{
    stream >> account.registeredEmployee >> account.id >> account.name >> account.meaning >> account.gender >>
    account.origin >> account.peoplesCount >> account.whenPeoplesCount ;

    return stream;
}

QList<QString>& operator<<(QList<QString>& dataUser, Account& account)
{
    dataUser << account.registeredEmployee << account.id << account.name << account.meaning <<
                account.gender << account.origin << account.peoplesCount << account.whenPeoplesCount;
    return dataUser;
}

