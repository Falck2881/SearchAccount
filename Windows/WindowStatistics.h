#ifndef WINDOWSTATISTICS_H
#define WINDOWSTATISTICS_H

#include "Window.h"
#include "Observers/ManagerBuilders.h"
#include <QTableWidget>

namespace Ui {
class WindowStatistics;
}

class WindowStatistics : public Window, Observers
{
    Q_OBJECT

    public:
        explicit WindowStatistics(std::shared_ptr<ManagerBuilders> subject);
        ~WindowStatistics();
    private:
        virtual void update(ManagerBuilders * const subject) final;
        void initializationTables(ManagerBuilders* const subject);
        void setTabsHeader(QList<BuilderTree*>  listBuilders);
        void placeCharacteristicsTreeInTable(QTableWidget* const table,BuilderTree* const builder);
        virtual void setConnection() final;
        Ui::WindowStatistics *ui;
};

#endif // WINDOWSTATISTICS_H
