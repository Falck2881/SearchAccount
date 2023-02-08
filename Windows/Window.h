#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QDebug>

class Window: public QWidget
{
    Q_OBJECT

    public:
        Window(Window* window);
        virtual ~Window(){}
    public slots:
        virtual void open();
        void close();
    private:
        Window* window;
    protected:
        virtual void setConnection(){};

};
#endif // WINDOW_H
