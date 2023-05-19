#include "newcell.h"
#include "ui_newcell.h"
#include "UI/w_chooselist/chooselist.h"
#include "UI/w_deck/NewCell/w_chooseposition/chooseposition.h"
#include "domain/database.h"
#include "UI/w_decklist/decklist.h"
#include "UI/w_deck/deck.h"
#include <QInputDialog>
#include "domain/domain.h"

NewCell::NewCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCell)
{
    ui->setupUi(this);


//    if (color == "black") {
//        ui->label_cell_color->setStyleSheet("background-color: black");
//    } else if (color == "red") {
//        ui->label_cell_color->setStyleSheet("background-color: red");
//    } else if (color == "green") {
//        ui->label_cell_color->setStyleSheet("background-color: green");
//    } else if (color == "blue") {
//        ui->label_cell_color->setStyleSheet("background-color: blue");
//    }





}

NewCell::~NewCell()
{
    delete ui;
}



void NewCell::on_btn_color_clicked()
{

    if (IfUserOwnerOfCard(DeckList::OpenedBoard->jsnBoard, Deck::TabIndex, CellNumber, Database::GetCurrentUser()) == 1 ){
        chooselist choose_color_window;
        choose_color_window.CellNum = CellNumber;
        choose_color_window.Cell = this;
        choose_color_window.exec();

    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}


void NewCell::setColor(QString Color)
{
    if (Color == "Black") {
        ui->label_cell_color->setStyleSheet("background-color: black");
    } else if (Color == "Red") {
        ui->label_cell_color->setStyleSheet("background-color: red");
    } else if (Color == "Green") {
        ui->label_cell_color->setStyleSheet("background-color: green");
    } else if (Color == "Blue") {
        ui->label_cell_color->setStyleSheet("background-color: blue");
    }
}



void NewCell::setTextData(QString cellText){
    ui->textEdit->clear();
    ui->textEdit->setPlainText(cellText);
}

void NewCell::setCellName(QString cellName)
{
    ui->cellname->clear();
    ui->cellname->setText(cellName);
}

void NewCell::setCoowners(QString Coowners)
{
    ui->coowner->clear();
    ui->coowner->setText(Coowners);
}

void NewCell::on_deleteButton_clicked()
{

    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {

        //DeckList::OpenedBoard->jsnBoard["Name"][Columns][Deck::TabIndex]["Cards"].erase(DeckList::OpenedBoard->jsnBoard["Name"][Columns][Deck::TabIndex]["Cards"].begin() + CellNumber);
        Database::DeleteCardFromColumn(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNumber);
        emit closeThisCell(CellNumber);

    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}


void NewCell::on_btn_coowner_clicked()
{
    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {

        QString Text = QInputDialog::getText(this, "Enter new owner", "Enter new owner login:", QLineEdit::Normal, "");

        if (Database::FindUser(Text, "x") != 0) {
            for (auto i : DeckList::OpenedBoard->jsnBoard["Owners"]) {
                if (i == Text.toStdString()) {
                    QMessageBox::warning(this, "not found", "такой юзер уже имеет права редактирования");
                    return;
                }
            }
            for (auto i : DeckList::OpenedBoard->jsnBoard["Columns"][Deck::TabIndex]["Cards"][CellNumber]["CardOwners"]) {
                if (i == Text.toStdString()) {
                    QMessageBox::warning(this, "not found", "такой юзер уже имеет права редактирования");
                    return;
                }
            }
            QMessageBox::warning(this, "not found", "успешно добавлен");
            DeckList::OpenedBoard->jsnBoard["Columns"][Deck::TabIndex]["Cards"][CellNumber]["CardOwners"].push_back(Text.toStdString());
            Database::AddOwnerToCard(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNumber, Text);
            QString Coowners;
            for (auto own : DeckList::OpenedBoard->jsnBoard["Columns"][Deck::TabIndex]["Cards"][CellNumber]["CardOwners"]) {
                Coowners += QString::fromStdString(own) + " ";
            }
            this->setCoowners(Coowners);
            return;
        } else {
            QMessageBox::warning(this, "not found", "такого юзера не сущетвует");
        }

    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}



void NewCell::on_btn_position_clicked()
{
    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {

        chooseposition position_window;
        position_window.exec();

    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}


void NewCell::on_btn_savetext_clicked()
{
    if (IfUserOwnerOfCard(DeckList::OpenedBoard->jsnBoard, Deck::TabIndex, CellNumber, Database::GetCurrentUser()) == 1 ){
        QString Text = ui->textEdit->toPlainText();
        Database::SetCardText(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNumber, Text);
        QMessageBox::information(this, "saved", "текст сохранен");
    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }


}

void NewCell::on_btn_rename_clicked()
{
    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {

        QString Text = QInputDialog::getText(this, "Enter new name", "Enter new name:", QLineEdit::Normal, "");
        Database::RenameCardFromColumn(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNumber, Text);
        ui->cellname->setText(Text);

    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}

