#ifndef CHOOSELIST_H
#define CHOOSELIST_H

#include <QDialog>
#include "UI/w_deck/NewCell/newcell.h"

namespace Ui {
class chooselist;
}

class chooselist : public QDialog
{
    Q_OBJECT

public:
    explicit chooselist(QWidget *parent = nullptr);
    ~chooselist();

    int CellNum;
    NewCell *Cell;

private slots:
    void on_btn_close_clicked();

    void on_btn_choose_clicked();

private:
    Ui::chooselist *ui;
};

#endif // CHOOSELIST_H
