#include "boardedit.h"
#include "ui_boardedit.h"
#include "UI/w_decklist/decklist.h"
#include "domain/database.h"

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
        QMessageBox::warning(this, "govno nabral", "запрещенные символы или пустая строка");
    }
    if (Database::FindUser(new_owner, "x") == 0) {
        QMessageBox::warning(this, "govno nabral", "такого пользователя не существует");
    } else {

        int flag = 0;
        for (auto i : DeckList::OpenedBoard->jsnBoard["Owners"]) {
            if (i == new_owner.toStdString()) {
                QMessageBox::warning(this, "govno nabral", "такой пользователь уже владеет доской");
                flag = 1;
            }
        }
        if (flag == 0) {
            QString BoardOwners;
            DeckList::OpenedBoard->jsnBoard["Owners"].push_back(new_owner.toStdString());
            for (auto Owners : DeckList::OpenedBoard->jsnBoard["Owners"]) {
                BoardOwners += QString::fromStdString(Owners) + ", ";
            }
            Database::AddOwnerToBoard(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), new_owner);
            DeckList::OpenedBoard->addBoardOwner(BoardOwners);
        }
    }

}


void BoardEdit::on_btn_Name_clicked()
{
    QString new_name = ui->lineEdit_name->text();
    if (new_name.isEmpty() or (!new_name.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$")))) {
        QMessageBox::warning(this, "govno nabral", "запрещенные символы или пустая строка");
    }
    if (Database::FindBoard(new_name) == 1) {
        Database::ChangeBoardName(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), new_name);
        DeckList::OpenedBoard->setBoardName(new_name);
    } else {
        QMessageBox::warning(this, "govno nabral", "имя занято");
    }
}


void BoardEdit::on_btn_Type_clicked()
{
    if (ui->radioButton_private->isChecked()) {
        ui->radioButton_public->setChecked(true);
        Database::ChangeBoardType(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), "public");
        DeckList::OpenedBoard->setBoardPrivacyType("public");
    } else {
        ui->radioButton_private->setChecked(true);
        Database::ChangeBoardType(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), "private");
        DeckList::OpenedBoard->setBoardPrivacyType("private");
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
