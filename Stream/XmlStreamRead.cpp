#include "XmlStreamRead.h"
#include <QXmlStreamAttribute>
#include <cassert>
#include <QDebug>

XmlStreamRead::XmlStreamRead(std::shared_ptr<QFile> file):streamRead{std::make_unique<QXmlStreamReader>()}
{
    openStreamOnlyForRead(file);
    skipStartsElementXmlFile();
}

void XmlStreamRead::openStreamOnlyForRead(std::shared_ptr<QFile> file)
{
    if(file->open(QIODevice::ReadOnly))
        streamRead->setDevice(file.get());
}


void XmlStreamRead::skipStartsElementXmlFile()
{
    bool openDevice = streamRead->device()->isOpen();
    assert(openDevice && "The file 'is not open' to read. "
                         "Before calling skipRootElementXmlFile() \n"
                         "openStreamOnlyForRead(QFile& file) call was expected");
    streamRead->readNextStartElement();
    streamRead->readNextStartElement();

    bool value = streamRead->isStartElement();
    assert(value  && "WARNING! - Element should to be open.");
}

void XmlStreamRead::readNextStartElement()
{
    streamRead->readNextStartElement();
}

QStringView XmlStreamRead::nameElement()
{
    return streamRead->name();
}

bool XmlStreamRead::isNotEndRootElement()
{
    return streamRead->isEndElement()?false:true;
}

bool XmlStreamRead::isData()
{
    bool data = false;

    while(!streamRead->atEnd())
    {
        streamRead->readNextStartElement();
        if(streamRead->name() == QString("foreign_names"))
        {
            data = true;
            break;
        }
    }

    return data;
}

QByteArray XmlStreamRead::readBlockData()
{
    QByteArray array;
    QDataStream dataStream(&array,QIODevice::WriteOnly);

    while(!streamRead->atEnd())
    {
         if(streamRead->isStartElement())
         {
            readAttributesInStream(dataStream);
            readElementsInStream(dataStream);
            streamRead->readNextStartElement();
         }
         else if(streamRead->isEndElement()){
             streamRead->readNextStartElement();
             break;
         }
    }
    return array;
}

void XmlStreamRead::readAttributesInStream(QDataStream &dataStream)
{
    if(streamRead->name() == QString("foreign_names"))
    {
        foreach(const QXmlStreamAttribute& attr, streamRead->attributes())
        {
            if(attr.qualifiedName() == QString("msdata:rowOrder"))
            {
                registeredEmployee = attr.value().toString();
                dataStream << registeredEmployee;
            }
        }
    }
}

void XmlStreamRead::readElementsInStream(QDataStream &dataStream)
{
    if(streamRead->name() == QString("id"))
    {
        id = streamRead->readElementText();
        dataStream << id;
    }
    else if(streamRead->name() == QString("name"))
    {
        name = streamRead->readElementText();
        dataStream << name;
    }
    else if(streamRead->name() == QString("meaning"))
    {
        meaning = streamRead->readElementText();
        dataStream << meaning;
    }
    else if(streamRead->name() == QString("gender"))
    {
        gender = streamRead->readElementText();
        dataStream << gender;
    }
    else if(streamRead->name() == QString("origin"))
    {
        origin = streamRead->readElementText();
        dataStream << origin;
    }
    else if(streamRead->name() == QString("PeoplesCount"))
    {
        peoplesCount = streamRead->readElementText();
        dataStream << peoplesCount;
    }
    else if(streamRead->name() == QString("WhenPeoplesCount"))
    {
        whenPeoplesCount = streamRead->readElementText();
        dataStream << whenPeoplesCount;
    }
    else if(streamRead->name() == QString("Source"))
    {
        sourse = streamRead->readElementText();
        dataStream << sourse;
    }
}
