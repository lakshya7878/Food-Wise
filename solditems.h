#ifndef SOLDITEMS_H
#define SOLDITEMS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class SoldItems;
}

class SoldItems : public QDialog
{
    Q_OBJECT

public:
    explicit SoldItems(QWidget *parent = nullptr);
    ~SoldItems();
    void Show();
private:
    Ui::SoldItems *ui;
    void updateUI();
};

#endif // SOLDITEMS_H
