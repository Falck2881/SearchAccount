#ifndef XMLSTREAMREAD_H
#define XMLSTREAMREAD_H

#include <QXmlStreamReader>
#include <QFile>
#include <QDataStream>
#include <memory>
#include <QStringView>

class XmlStreamRead
{
    public:
        XmlStreamRead(std::shared_ptr<QFile> file);
        bool isNotEndRootElement();
        QByteArray readBlockData();
        bool isData();
        void readNextStartElement();
        QStringView nameElement();
    private:
        QString id;
        QString registeredEmployee;
        QString name;
        QString meaning;
        QString gender;
        QString origin;
        QString peoplesCount;
        QString whenPeoplesCount;
        QString sourse;
        void openStreamOnlyForRead(std::shared_ptr<QFile> file);
        void skipStartsElementXmlFile();
        void readAttributesInStream(QDataStream& dataStream);
        void readElementsInStream(QDataStream& dataStream);
        std::unique_ptr<QXmlStreamReader> streamRead;
};
#endif // XMLSTREAMREAD_H
