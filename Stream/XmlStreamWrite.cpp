#include "XmlStreamWrite.h"
#include <QXmlStreamAttribute>

XmlStreamWrite::XmlStreamWrite(QFile* file):streamWrite(new QXmlStreamWriter(file))
{
}

void XmlStreamWrite::write()
{
    streamWrite->setAutoFormatting(true);
    streamWrite->writeStartElement("UserData");
    streamWrite->writeAttribute("ID",id);
    streamWrite->writeAttribute("Pass", pass);
    streamWrite->writeTextElement("Name", name);
    streamWrite->writeTextElement("Surname", surname);
    streamWrite->writeTextElement("Data_Birth", dataBirth);
    streamWrite->writeTextElement("Position", position);
    streamWrite->writeTextElement("Number_Phone", numberPhone);
    streamWrite->writeEndElement();

}

XmlStreamWrite& operator<<(XmlStreamWrite& stream, QByteArray array)
{
    QDataStream dataStream(&array, QIODevice::ReadOnly);

    dataStream >> stream.id >> stream.pass >> stream.name >> stream.surname >>
    stream.dataBirth >> stream.position >> stream.numberPhone;
    stream.write();

    return stream;
}
