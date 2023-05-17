#ifndef BOARDEDIT_H
#define BOARDEDIT_H

#include <QDialog>

namespace Ui {
class BoardEdit;
}

class BoardEdit : public QDialog
{
    Q_OBJECT

public:
    explicit BoardEdit(QWidget *parent = nullptr);
    ~BoardEdit();

private slots:

    void on_btn_Back_clicked();

    void on_btn_Owner_clicked();

    void on_btn_Name_clicked();

    void on_btn_Type_clicked();

private:
    Ui::BoardEdit *ui;
};

#endif // BOARDEDIT_H
