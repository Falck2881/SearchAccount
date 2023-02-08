#ifndef OBSERVERS_H
#define OBSERVERS_H

class ManagerBuilders;
#include <memory>

class Observers
{
    public:
        virtual ~Observers(){}
        virtual void update(ManagerBuilders* subject) = 0;
    protected:
        Observers(){}

};

#endif // OBSERVERS_H
