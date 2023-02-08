#include "Tree.h"
#include <QDebug>

Tree::Tree():_sizeVertex{1},_checksum{0},_height{1}
{

}
void Tree::serializationAccountUser(Account account)
{
    QFile file(QString("dataUser.dat"));
    if(file.open(QIODevice::WriteOnly)){
        QDataStream stream(&file);
        stream << account;
        file.close();
    }
    else{
        qDebug() << "Warning! FILE NOT OPEN!";
    }
}

uint64_t Tree::mediumHeight() const
{
    return _mediumHeight;
}

uint64_t Tree::height() const
{
    return _height;
}

uint64_t Tree::checksum() const
{
    return _checksum ;
}

void Tree::changeHeight(const uint64_t currentHeight)
{
    _height = currentHeight + 1;
}

void Tree::changeSizeVertex(const uint64_t currentSize)
{
    _sizeVertex = currentSize + 1;
}

void Tree::changeCheckSum(const uint64_t currentChecksum)
{
    _checksum = currentChecksum;
}

uint64_t Tree::sizeVertex() const
{
    return _sizeVertex;
}

void Tree::changeMediumHeight(const uint64_t mediumHeight)
{
    _mediumHeight = mediumHeight;
}

