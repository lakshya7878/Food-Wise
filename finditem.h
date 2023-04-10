#ifndef FINDITEM_H
#define FINDITEM_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class FindItem;
}

class FindItem : public QDialog
{
    Q_OBJECT

public:
    explicit FindItem(QWidget *parent = nullptr);
    ~FindItem();

private slots:
    void on_btnFind_clicked();

private:
    Ui::FindItem *ui;

};
#endif // FINDITEM_H
