#ifndef CELL_H
#define CELL_H

#include <QDialog>

namespace Ui {
class cell;
}

class cell : public QDialog
{
    Q_OBJECT

public:
    explicit cell(QWidget *parent = nullptr);
    ~cell();

private slots:
    void on_btn_back_clicked();

    void on_btn_Save_clicked();

    void on_btn_Change_User_clicked();

    void on_btn_change_column_clicked();

private:
    Ui::cell *ui;
};

#endif // CELL_H
