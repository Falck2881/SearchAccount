#ifndef WINDOWDISPLAY_H
#define WINDOWDISPLAY_H

#include "Window.h"
#include "Observers/ManagerBuilders.h"
#include <QPushButton>
#include <QTableWidget>
#include <QFrame>
#include <cstdint>

class WindowDisplay: public Window, Observers
{
    Q_OBJECT

    public:
        explicit WindowDisplay(std::shared_ptr<ManagerBuilders> subject);
    private:
        virtual void update(ManagerBuilders *subject) final;
        void initializationWindow();
        void setPropertyWindow();
        void createWidgets();
        void placeCreatedWidgetsInCurrentWindow();
        virtual void setConnection() final;
        QPushButton* backButton;
        QTableWidget* table;
        QFrame* frame;
        Tree* tree;
};

#endif // WINDOWDISPLAY_H
