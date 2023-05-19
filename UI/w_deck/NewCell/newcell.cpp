#include "newcell.h"
#include "ui_newcell.h"
#include "domain/database.h"
#include "UI/w_decklist/decklist.h"
#include "UI/w_deck/deck.h"

NewCell::NewCell(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewCell)
{
    ui->setupUi(this);
}

NewCell::~NewCell()
{
    delete ui;
}


void NewCell::setTextData(QString cellText){
    ui->textEdit->clear();
    ui->textEdit->setPlainText(cellText);
}

void NewCell::on_deleteButton_clicked()
{
    Database::DeleteCardFromColumn(QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]), Deck::TabIndex, CellNumber);
    emit closeThisCell(CellNumber);
}

