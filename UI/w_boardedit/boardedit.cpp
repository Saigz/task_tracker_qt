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


void BoardEdit::on_btn_Back_clicked()
{
    this->close();
}


void BoardEdit::on_btn_Owner_clicked()
{

}


void BoardEdit::on_btn_Name_clicked()
{

}


void BoardEdit::on_btn_Type_clicked()
{

}

