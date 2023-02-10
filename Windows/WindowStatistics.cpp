#include "WindowStatistics.h"
#include "ui_WindowStatistics.h"
#include <QHeaderView>

WindowStatistics::WindowStatistics(std::shared_ptr<ManagerBuilders> subject):Window(this),
                                                                             ui(new Ui::WindowStatistics)
{
    ui->setupUi(this);
    subject->append(this);
    ui->tableWidget->horizontalHeader()->setVisible(true);
    ui->tableWidget_2->horizontalHeader()->setVisible(true);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget_2->verticalHeader()->setVisible(true);
    setConnection();
}

void WindowStatistics::setConnection()
{
    connect(ui->backButton, &QPushButton::clicked, this, &Window::close);
}

void WindowStatistics::update(ManagerBuilders *subject)
{
    initializationTables(subject);
}

void WindowStatistics::initializationTables(ManagerBuilders * const subject)
{
    QList<BuilderTree*> listBuilders;
    listBuilders << subject->getFirstBuilder() << subject->getSecondBuilder();
    QList<QTableWidget*> listTabs{ui->tableWidget, ui->tableWidget_2};
    setTabsHeader(listBuilders);

    for(uint8_t index = 0; index != listBuilders.size(); ++index)
        placeCharacteristicsTreeInTable(listTabs.at(index), listBuilders.at(index));
}

void WindowStatistics::setTabsHeader(QList<BuilderTree*> listBuilders)
{
    for(uint8_t index = 0; index != listBuilders.size(); ++index)
        ui->tabWidget->setTabText(index,listBuilders.at(index)->nameBuilder());
}

void WindowStatistics::placeCharacteristicsTreeInTable(QTableWidget* const table, BuilderTree* const builder)
{
    QVector<QString> currantArrayCharacteristicsTree;
    for(uint8_t row = 0; row != table->rowCount(); ++row)
    {
        currantArrayCharacteristicsTree = builder->arrayCharacteristicsTree(row);
        for(uint8_t column = 0; column != table->columnCount(); ++column)
                table->setItem(row,column,new QTableWidgetItem(currantArrayCharacteristicsTree.at(column)));
    }
}

WindowStatistics::~WindowStatistics()
{
    delete ui;
}
