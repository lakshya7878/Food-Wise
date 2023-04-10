#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ptrAddItem = new AddItem(this);
    ptrItemReport = new ItemsReport(this);

    ptrSpoiledItems = new SpoiledItems(this);
    ptrSoldITems = new SoldItems(this);
    ptrExpiredItems = new ExpiredItems(this);
    ptrReturnedItems = new ReturnedItems(this);
    ptrAvailableItems = new AvailableItems(this);

    ptrUpdateItem = new UpdateItem(this);
    ptrFindItem = new FindItem(this);

    this->setFixedSize(500,400);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ptrAddItem;
    delete ptrItemReport;

    delete ptrSpoiledItems;
    delete ptrSoldITems;
    delete ptrExpiredItems;
    delete ptrReturnedItems;
    delete ptrFindItem;
    delete ptrUpdateItem;
    MyDB::ResetInstance();
}

void MainWindow::on_btnAddItem_clicked()
{
    ptrAddItem->Show();
}

void MainWindow::on_btnUpdateItem_clicked()
{
    ptrUpdateItem->Show();
}

void MainWindow::on_btnSoldItems_clicked()
{
    ptrSoldITems->Show();
}

void MainWindow::on_btnReport_clicked()
{
    ptrItemReport->Show();
}

void MainWindow::on_btnExpiredItems_clicked()
{
    ptrExpiredItems->Show();
}

void MainWindow::on_btnAvailableItems_clicked()
{
    ptrAvailableItems->Show();
}

void MainWindow::on_btnSpoiledItem_clicked()
{
    ptrSoldITems->Show();
}

void MainWindow::on_btnReturnItems_clicked()
{
    ptrReturnedItems->Show();
}

void MainWindow::on_btnFindItem_clicked()
{
    ptrFindItem->show();
}
