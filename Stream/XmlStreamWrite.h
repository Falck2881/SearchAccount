#ifndef XMLSTREAMWRITE_H
#define XMLSTREAMWRITE_H

#include <QXmlStreamWriter>
#include <QFile>
#include <QDataStream>
#include <QString>

class XmlStreamWrite
{
    public:
        XmlStreamWrite(QFile* file);
        friend XmlStreamWrite& operator<<(XmlStreamWrite& stream, QByteArray array);
    private:
        void write();
        QXmlStreamWriter* streamWrite;
        QString id;
        QString pass;
        QString name;
        QString surname;
        QString dataBirth;
        QString position;
        QString numberPhone;
};

#endif // XMLSTREAMWRITE_H
