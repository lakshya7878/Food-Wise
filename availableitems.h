#ifndef AVAILABLEITEMS_H
#define AVAILABLEITEMS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class AvailableItems;
}

class AvailableItems : public QDialog
{
    Q_OBJECT

public:
    explicit AvailableItems(QWidget *parent = nullptr);
    ~AvailableItems();
    void Show();
private:
    Ui::AvailableItems *ui;
    void updateUI();
};

#endif // AVAILABLEITEMS_H
