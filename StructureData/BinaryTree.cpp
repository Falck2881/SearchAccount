#include "Warnings/Warning.h"
#include "BinaryTree.h"
#include <QList>
#include <QDebug>

BinaryTree::BinaryTree():leftChildNode{nullptr},rightChildNode{nullptr}
{
}

void BinaryTree::search(uint64_t key)
{
    if(key == this->dataUser.key()){
        serializationAccountUser(this->dataUser);
    }
    else if(this->leftChildNode != nullptr && key < this->key()){
        search(key, this->leftChildNode);
    }
    else if(this->rightChildNode != nullptr && key > this->key()){
        search(key, this->rightChildNode);
    }
    else{
        throw new Warning("User with ID-" + QString::number(key) + " no exists");
    }

}

void BinaryTree::search(uint64_t key, BinaryTree* currentTree)
{
    if(key == currentTree->key()){
        serializationAccountUser(currentTree->dataUser);
    }
    else if(currentTree->leftChildNode != nullptr && key < currentTree->key()){
        search(key, currentTree->leftChildNode);
    }
    else if(currentTree->rightChildNode != nullptr && key > currentTree->key()){
        search(key, currentTree->rightChildNode);
    }
    else{
        throw new Warning("User with ID-" + QString::number(key) + " no exists");
    }
}

uint64_t BinaryTree::key()
{
    return dataUser.key();
}

void BinaryTree::setData(Account data)
{
    dataUser = data;
    _checksum = dataUser.registrationNumber();
}

void BinaryTree::returnStartingChecksum()
{
    _checksum = dataUser.registrationNumber();
}

void BinaryTree::treeTraversal(QTableWidget *tableWinDisplay)
{
    table = tableWinDisplay;
    insertAllDataInTable();
}

void BinaryTree::insertAllDataInTable()
{
    uint64_t row{0};
    insertAllDataInTable(row, leftChildNode);
    extractDataFromNodeInTable(row,this);
    insertAllDataInTable(row, rightChildNode);
}

void BinaryTree::insertAllDataInTable(uint64_t& row, BinaryTree* tree)
{
    if(tree != nullptr)
    {
        insertAllDataInTable(row, tree->leftChildNode);
        extractDataFromNodeInTable(row, tree);
        insertAllDataInTable(row , tree->rightChildNode);
    }
}

void BinaryTree::extractDataFromNodeInTable(uint64_t& row, BinaryTree *tree)
{
    QList<QString> dataAccountUser;
    Account currentAccountUser{tree->dataUser} ;
    dataAccountUser << currentAccountUser;

    table->setRowCount(row);
    table->insertRow(table->rowCount());
    for(uint8_t column = 0; column != dataAccountUser.size(); ++column)
        table->setItem(row,column, new QTableWidgetItem(QString(dataAccountUser.at(column))));

    row+=1;
}

void BinaryTree::removeAll()
{
    removeAll(this->leftChildNode);
    removeAll(this->rightChildNode);
    delete this;
}

void BinaryTree::removeAll(BinaryTree *node)
{
    if(node != nullptr)
    {
        removeAll(node->leftChildNode);
        removeAll(node->rightChildNode);
        delete node;
    }
}
