#include "boardedit.h"
#include "ui_boardedit.h"
#include "UI/w_decklist/decklist.h"

#include <QRegularExpression>
#include <QMessageBox>

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
    if (new_owner.isEmpty() or (!new_owner.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$")))) {
        QMessageBox::warning(this, "govno nabral", "иди нахуй дебил");
    }
}


void BoardEdit::on_btn_Name_clicked()
{
    QString new_name = ui->lineEdit_name->text();
    if (new_name.isEmpty() or (!new_name.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$")))) {
        QMessageBox::warning(this, "govno nabral", "иди нахуй дебил");
    }
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
    QString Type;

    if (ui->radioButton_private->isChecked()) {
        Type = "private";
    } else if (ui->radioButton_public->isChecked()) {
        Type = "public";
    }

    // db code


    close();
}
