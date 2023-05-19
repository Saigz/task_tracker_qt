#include "boardedit.h"
#include "ui_boardedit.h"
#include "UI/w_decklist/decklist.h"
#include "domain/database.h"
#include "domain/domain.h"

#include <QRegularExpression>
#include <QMessageBox>

BoardEdit::BoardEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BoardEdit)
{
    ui->setupUi(this);

    QString Type = QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Type"]);
    if (Type == "private") {
        ui->radioButton_private->setChecked(true);
        ui->radioButton_public->setChecked(false);
    } else if (Type == "public") {
        ui->radioButton_private->setChecked(false);
        ui->radioButton_public->setChecked(true);
    }
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
            DeckList::OpenedBoard->setBoardOwners(BoardOwners);
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
    close();
}

void BoardEdit::on_btn_del_owner_clicked()
{
    QString del_owner = ui->lineEdit_del_owner->text();
    if (InputValidation(del_owner) == 0 and Database::FindUser(del_owner, "x") == 0) {
        QMessageBox::warning(this, "govno nabral", "запрещенные символы или пустая строка или пользователя не существует" );
    } else {
        if (DeckList::OpenedBoard->jsnBoard["Owners"].size() < 2) {
            QMessageBox::warning(this, "afsd", "нельзя удалить последнего владельца доски" );
            return;
        }
        int i = 0;
        for (auto own : DeckList::OpenedBoard->jsnBoard["Owners"]) {
            if (own == del_owner.toStdString()) {

                QString BoardOwners;
                DeckList::OpenedBoard->jsnBoard["Owners"].erase(DeckList::OpenedBoard->jsnBoard["Owners"].begin() + i);
                for (auto Owners : DeckList::OpenedBoard->jsnBoard["Owners"]) {
                    BoardOwners += QString::fromStdString(Owners) + ", ";
                }
                Database::DeleteOwnerFromBoard(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), del_owner);
                DeckList::OpenedBoard->setBoardOwners(BoardOwners);
                QMessageBox::warning(this, "успех", "успешно удалили владельца доски" );
                return;
            }
            i++;
        }
        QMessageBox::warning(this, "govno nabral", "пользователь итак не владеет доской" );
        return;
    }
}

