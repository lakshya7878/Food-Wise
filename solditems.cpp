#include "solditems.h"
#include "ui_solditems.h"

SoldItems::SoldItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SoldItems)
{
    ui->setupUi(this);
}

SoldItems::~SoldItems()
{
    delete ui;
}

void SoldItems::Show()
{
    updateUI();
    this->show();
}

void SoldItems::updateUI()
{
    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select * from cppbuzz_items where Status='Sold'");

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
