#include "returneditems.h"
#include "ui_returneditems.h"

ReturnedItems::ReturnedItems(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReturnedItems)
{
    ui->setupUi(this);
}

ReturnedItems::~ReturnedItems()
{
    delete ui;
}

void ReturnedItems::Show()
{
    updateUI();
    show();
}

void ReturnedItems::updateUI()
{
    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select * from cppbuzz_items where Status='Return'");

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
