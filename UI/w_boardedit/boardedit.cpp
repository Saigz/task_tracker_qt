#include "boardedit.h"
#include "ui_boardedit.h"
#include "UI/w_decklist/decklist.h"

BoardEdit::BoardEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoardEdit)
{
    ui->setupUi(this);
}

BoardEdit::~BoardEdit()
{
    delete ui;
}



void BoardEdit::on_btn_Owner_clicked()
{
    QString new_owner = ui->lineEdit_owner->text();

}


void BoardEdit::on_btn_Name_clicked()
{
    QString new_name = ui->lineEdit_name->text();
}


void BoardEdit::on_btn_Type_clicked()
{
    if (ui->radioButton_private->isChecked()) {
        ui->radioButton_public->setChecked(true);
    } else {
        ui->radioButton_private->setChecked(true);
    }

}


void BoardEdit::on_btn_Back_clicked()
{
    close();
    DeckList::OpenedBoard->show();
}

