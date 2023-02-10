#include "WindowDisplay.h"
#include <QGridLayout>
#include <QTableWidgetItem>
#include <QRect>
#include <QStringList>
#include <QHeaderView>

WindowDisplay::WindowDisplay(std::shared_ptr<ManagerBuilders> subject):Window(this)
{
    subject->append(this);
    initializationWindow();
    setConnection();
}

void WindowDisplay::initializationWindow()
{
    setPropertyWindow();
    createWidgets();
    placeCreatedWidgetsInCurrentWindow();
}

void WindowDisplay::setPropertyWindow()
{
    this->setFixedSize(900,500);
    this->setWindowTitle(QString("Display Accounts"));
    this->setWindowFlags(Qt::WindowStaysOnTopHint);
}

void WindowDisplay::createWidgets()
{
    frame = new QFrame(this);
    frame->setGeometry(QRect(0,0,900,500));
    frame->setFrameStyle(QFrame::Panel);
    frame->setLineWidth(2);
    frame->setMidLineWidth(3);

    table = new QTableWidget(frame);
    table->setFixedSize(875, 400);
    table->setColumnCount(8);
    QList<QString> headers{"№ Employee","ID","Name","Meaning","Gender",
                           "Nationality","Number of visits", "Time last of visits"};
    table->setHorizontalHeaderLabels(headers);
    table->setMinimumSize(QSize(875, 400));
    table->setMaximumSize(QSize(875, 400));
    table->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setDragDropMode(QAbstractItemView::NoDragDrop);
    table->setSelectionMode(QAbstractItemView::NoSelection);
    table->setSelectionBehavior(QAbstractItemView::SelectColumns);
    table->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
    table->setHorizontalScrollMode(QAbstractItemView::ScrollPerItem);
    table->horizontalHeader()->setStretchLastSection(true);
    table->verticalHeader()->setStretchLastSection(true);
    table->horizontalHeader()->setVisible(true);
    table->verticalHeader()->setVisible(true);

    backButton = new QPushButton(QString("Back"));
    backButton->setFixedSize(170,25);
}

void WindowDisplay::placeCreatedWidgetsInCurrentWindow()
{
    QGridLayout* layout = new QGridLayout(frame);
    layout->addWidget(table, 0, 0, Qt::AlignHCenter);
    layout->addWidget(backButton, 1, 0, Qt::AlignHCenter);
    this->setLayout(layout);
}

void WindowDisplay::setConnection()
{
    connect(backButton, &QPushButton::clicked, this, &Window::close);
}

void WindowDisplay::update(ManagerBuilders *subject)
{
    Tree* tree = subject->getReadyTree();
    tree->treeTraversal(table);
}

