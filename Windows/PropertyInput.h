#ifndef PROPERTYINPUT_H
#define PROPERTYINPUT_H

class PropertyInput
{
    public:
        virtual ~PropertyInput(){}
        virtual void setPropertyInput() = 0;
        virtual void createValidator() = 0;
        virtual void setValidator() = 0;
    protected:
        PropertyInput(){}
};

#endif // PROPERTYINPUT_H
