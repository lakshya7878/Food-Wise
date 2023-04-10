#include "itemsreport.h"
#include "ui_itemsreport.h"

ItemsReport::ItemsReport(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemsReport)
{
    ui->setupUi(this);
}

ItemsReport::~ItemsReport()
{
    delete ui;
}

void ItemsReport::Show()
{
    updateUI();
    this->show();
}

void ItemsReport::updateUI()
{
       qDebug() << "in init()";
       QSqlQueryModel * model = new QSqlQueryModel(this);

       QSqlQuery query( MyDB::getInstance()->getDBInstance());
       query.prepare("select * from cppbuzz_items order by Id desc");

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
