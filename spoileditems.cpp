#include "spoileditems.h"
#include "ui_spoileditems.h"

SpoiledItems::SpoiledItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SpoiledItems)
{
    ui->setupUi(this);
}

SpoiledItems::~SpoiledItems()
{
    delete ui;
}

void SpoiledItems::Show()
{
    updateUI();
    this->show();
}

void SpoiledItems::updateUI()
{
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select * from cppbuzz_items where Status='Spoiled'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
       qDebug() << "== success query fetch()";

    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();

}
