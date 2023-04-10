#ifndef SPOILEDITEMS_H
#define SPOILEDITEMS_H

#include <QDialog>
#include "mydb.h"

namespace Ui {
class SpoiledItems;
}

class SpoiledItems : public QDialog
{
    Q_OBJECT

public:
    explicit SpoiledItems(QWidget *parent = nullptr);
    ~SpoiledItems();
     void Show();

private:
    Ui::SpoiledItems *ui;
    void updateUI();
};

#endif // SPOILEDITEMS_H
