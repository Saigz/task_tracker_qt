#include "chooselist.h"
#include "ui_chooselist.h"
#include <iostream>
#include "UI/w_deck/NewCell/newcell.h"
#include "domain/database.h"
#include "UI/w_decklist/decklist.h"

chooselist::chooselist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooselist)
{
    ui->setupUi(this);
}

chooselist::~chooselist()
{
    delete ui;
}

void chooselist::on_btn_close_clicked()
{
    close();
}


void chooselist::on_btn_choose_clicked()
{
    QListWidgetItem curr_item;
    curr_item = *ui->listWidget->item(ui->listWidget->currentRow());
    QString curr_item_string = curr_item.text().split(" ").at(0);
    std::cout << curr_item_string.toStdString() << std::endl;
    Database::ChangeColorOfCard(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNum, curr_item_string);
    Cell->setColor(curr_item_string);
    close();
}

