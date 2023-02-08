#ifndef TREE_H
#define TREE_H

#include "Account.h"
#include <cstdint>
#include <memory>
#include <QTableWidget>

class Tree
{
    public:
        Tree();
        virtual ~Tree(){}
        virtual void removeAll() = 0;
        uint64_t height() const;
        uint64_t sizeVertex() const;
        uint64_t checksum() const;
        uint64_t mediumHeight() const;
        void changeHeight(const uint64_t currentHeight);
        void changeSizeVertex(const uint64_t currentSize);
        void changeCheckSum(const uint64_t currentChecksum);
        void changeMediumHeight(const uint64_t mediumHeight);
        virtual void treeTraversal(QTableWidget* table) = 0;
        virtual void search(uint64_t key) = 0;
        virtual void setData(Account data) = 0;
    protected:
        void serializationAccountUser(Account account);
        uint64_t _sizeVertex;
        uint64_t _checksum;
        uint64_t _height;
        uint64_t _mediumHeight;
        QTableWidget* table;
};

#endif // TREE_H
