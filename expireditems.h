#ifndef EXPIREDITEMS_H
#define EXPIREDITEMS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class ExpiredItems;
}

class ExpiredItems : public QDialog
{
    Q_OBJECT

public:
    explicit ExpiredItems(QWidget *parent = nullptr);
    ~ExpiredItems();
     void Show();
private:
    Ui::ExpiredItems *ui;
        void updateUI();
};

#endif // EXPIREDITEMS_H
