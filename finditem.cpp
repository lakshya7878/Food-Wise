#include "finditem.h"
#include "ui_finditem.h"

FindItem::FindItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FindItem)
{
    ui->setupUi(this);
    ui->rdoName->setChecked(true);
}

FindItem::~FindItem()
{
    delete ui;
}

void FindItem::on_btnFind_clicked()
{
    QString sValue = ui->txtValue->text();
    QString sCriteriaColum = "";

    if(ui->rdoId->isChecked())
        sCriteriaColum="Id";
    else if (ui->rdoName->isChecked())
        sCriteriaColum="Name";
    else if (ui->rdoQuantity->isChecked())
        sCriteriaColum="Quantity";
    else if (ui->rdoSellingPrice->isChecked())
        sCriteriaColum = "SellingPrice";
    else
        sCriteriaColum = "Name";

    qDebug() << "in init()";
    QSqlQueryModel * model = new QSqlQueryModel(this);

    QSqlQuery query( MyDB::getInstance()->getDBInstance());
    query.prepare("select * from cppbuzz_items where " +sCriteriaColum+" like '%" + sValue + "%'");

    if(!query.exec())
       qDebug() << query.lastError().text() << query.lastQuery();
    else
    {
       if(query.numRowsAffected()>0)
       qDebug() << "== success query fetch() : " << query.lastQuery();
       else {
           qDebug() << " No record ! found ";
           qDebug() << " Query is : " << query.lastQuery();
       }
    }
    while(query.next())
    qDebug()<<query.value(0).toString();

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "rows are : " << model->rowCount();
    ui->tableView->show();
}
