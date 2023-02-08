#include "BalancedTree.h"
#include <QDebug>
#include "Warnings/Warning.h"

QVector<uint64_t> copyUserKeys(QVector<Account> userAccounts);

BalancedTree::BalancedTree(const qsizetype coefficient):maxSizeStoredData(2*coefficient),
                                                       maxSizeDecendants((2*coefficient)+2)
{
    setMaximumSizeStoredData();
    setMaximumSizePossibleDescendants();
}

void BalancedTree::setMaximumSizeStoredData()
{
    dataUser.reserve(maxSizeStoredData);
}

void BalancedTree::setMaximumSizePossibleDescendants()
{
    descendants.reserve(maxSizeDecendants);
}

void BalancedTree::search(uint64_t key)
{
    for(int64_t indexData = 0; indexData <= this->dataUser.size(); ++indexData)
    {
        if(indexData != this->dataUser.size()){
            if(key == this->dataUser[indexData].key()){
                serializationAccountUser(this->dataUser.at(indexData));
                break;
            }
        }
        else if(indexData == this->dataUser.size() && !this->descendants.isEmpty()){
            QVector<uint64_t> userKeys{copyUserKeys(this->dataUser)};
            userKeys.push_back(key);
            std::sort(userKeys.begin(), userKeys.end());
            int64_t indexDescendant{userKeys.indexOf(key)};
            search(key,this->descendants.at(indexDescendant));
        }
        else{
            throw new Warning("User with ID-" + QString::number(key) + " no exists");
        }
    }
}

QVector<uint64_t> copyUserKeys(QVector<Account> userAccounts)
{
    QVector<uint64_t> keys;
    foreach(auto acc, userAccounts)
        keys.push_back(acc.key());
    return keys;
}

void BalancedTree::search(uint64_t key, BalancedTree* currentNode)
{
    for(int64_t indexData = 0; indexData <= currentNode->dataUser.size(); ++indexData)
    {
        if(indexData != currentNode->dataUser.size()){
            if(key == currentNode->dataUser[indexData].key()){
                serializationAccountUser(currentNode->dataUser.at(indexData));
                break;
            }
        }
        else if(indexData == currentNode->dataUser.size() && !currentNode->descendants.isEmpty()){
            QVector<uint64_t> userKeys{copyUserKeys(currentNode->dataUser)};
            userKeys.push_back(key);
            std::sort(userKeys.begin(), userKeys.end());
            int64_t indexDescendant{userKeys.indexOf(key)};
            search(key,currentNode->descendants.at(indexDescendant));
        }
        else{
            throw new Warning("User with ID-" + QString::number(key) + " no exists");
        }
    }
}

void BalancedTree::setData(Account data)
{
    dataUser.push_back(data);
    _checksum+=dataUser.last().registrationNumber();
}

void BalancedTree::setDataInBegin(Account data)
{
    dataUser.push_front(data);
    _checksum+=dataUser.front().registrationNumber();
}

bool BalancedTree::isTerminalVertex() const
{
    return _height == 1?true:false;
}

bool BalancedTree::notMaximumSizeData() const
{
    return dataUser.size() != maxSizeStoredData ?true:false;
}

bool BalancedTree::notMaximumNumberDescendants() const
{
    return descendants.size() != maxSizeDecendants? true:false;
}

bool BalancedTree::maximumSizeData() const
{
    return dataUser.size() == maxSizeStoredData ?true:false;
}

bool BalancedTree::maximumNumberDescendants() const
{
    return descendants.size() == maxSizeDecendants ? true:false;
}

void BalancedTree::treeTraversal(QTableWidget *tableWinDisplay)
{
    table = tableWinDisplay;
    insertAllDataInTable();
}

void BalancedTree::insertAllDataInTable(uint64_t row)
{
    if(this->descendants.size() != 0)
    {
        for(int i = 0; i < this->descendants.size(); ++i){
            insertAllDataInTable(row,this->descendants.at(i));
            if(i < this->dataUser.size())
                extractDataFromNodeInTable(row,this->dataUser.at(i));
        }
    }
}

void BalancedTree::insertAllDataInTable(uint64_t& row, BalancedTree *tree)
{
    if(tree->descendants.size() == 0)
    {
        for(int j = 0; j < tree->dataUser.size(); ++j)
            extractDataFromNodeInTable(row,tree->dataUser.at(j));
    }
    else{
        for(int i = 0; i < tree->descendants.size(); ++i){
            insertAllDataInTable(row,tree->descendants.at(i));
            if(i < tree->dataUser.size())
                extractDataFromNodeInTable(row,tree->dataUser.at(i));
        }
    }
}

void BalancedTree::extractDataFromNodeInTable(uint64_t& row, Account currentAccount)
{
    QList<QString> dataUserAccount;
    dataUserAccount << currentAccount;
    table->setRowCount(row);
    table->insertRow(table->rowCount());

    for(qsizetype column = 0; column < dataUserAccount.size(); ++column)
        table->setItem(row,column, new QTableWidgetItem(dataUserAccount.at(column)));

    row+=1;
}

void BalancedTree::removeAll()
{
    if(this->descendants.size() != 0)
    {
        for(int i = 0; i <= this->descendants.size(); ++i){
            if(this->descendants.isEmpty()){
                delete this;
                break;
            }
            else{
                removeAll(this->descendants[i]);
                this->descendants.removeFirst();
            }
        }
    }
}

void BalancedTree::removeAll(BalancedTree* currentNode)
{
    if(currentNode->descendants.size() == 0){
        delete currentNode;
        currentNode = nullptr;
    }
    else{
        for(int i = 0; i <= currentNode->descendants.size(); ++i){
            if(currentNode->descendants.isEmpty()){
                delete currentNode;
                currentNode = nullptr;
                break;
            }
            else{
                removeAll(currentNode->descendants[i]);
                currentNode->descendants.removeFirst();
            }
        }
    }
}

