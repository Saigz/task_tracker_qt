#include "cell.h"
#include "ui_cell.h"

cell::cell(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cell)
{
    ui->setupUi(this);

    ui->Header->setText("ABOBA"); // CELL  NAME
    ui->Text->setPlainText("HUI");  //  CELL TEXT
    ui->label_cur_user->setText("YA  NAHUII"); // CELL USER
}

cell::~cell()
{
    delete ui;
}

void cell::on_btn_back_clicked()
{
    close();
}


void cell::on_btn_Save_clicked()
{
    QString Header_text = ui->Header->text();
    QString Main_text = ui->Text->placeholderText();

    // обновить в дб инфу
    close();
}


void cell::on_btn_Change_User_clicked()
{
    // думаю как  реализовать пока что(скорее  всего еще  один диалог)
}


void cell::on_btn_change_column_clicked()
{
    // тоже думаю как  реализовать пока что(скорее  всего еще  один диалог)
}

