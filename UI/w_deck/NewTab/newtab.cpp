#include "newtab.h"
#include "ui_newtab.h"
#include "UI/w_decklist/decklist.h"
#include "UI/w_deck/deck.h"
#include "domain/database.h"
#include "UI/w_deck/deck.h"
#include "QMessageBox"
#include "domain/domain.h"

NewTab::NewTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::NewTab)
{
    ui->setupUi(this);
    cellNumberTotal = 0;
}

NewTab::~NewTab()
{
    delete ui;
}

void NewTab::Swap(NewCell *First, NewCell *Second)
{
    //поменять индексы
    //поменять порядок в массиве
    //поменять расположение в лейауте


//    ui->cellLayout->removeItem(First->);
//    ui->cellLayout->removeItem(Second);

//    swap(allCellPtr[First->CellNumber], allCellPtr[Second->CellNumber]);
//    swap(First->CellNumber, Second->CellNumber);


//    ui->cellLayout->addWidget(First, 0,  First->CellNumber);
//    ui->cellLayout->addWidget(First, 0,  Second->CellNumber);

}

void NewTab::on_pushButton_clicked()
{
//    int first = 1;
//    int sec = 2;
//    NewCell *tmpFirst = allCellPtr[first];
//    NewCell *tmpSec = allCellPtr[sec];
//    ui->cellLayout->removeWidget(allCellPtr[first]);
//    ui->cellLayout->addWidget(tmpSec, 0,  first);
//    ui->cellLayout->removeWidget(allCellPtr[sec]);
//    ui->cellLayout->addWidget(tmpFirst, 0,  sec);

    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {
        addNewCell();
    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}


void NewTab::initCells() {

    for (auto Card : DeckList::OpenedBoard->jsnBoard["Columns"][Deck::TabIndex]["Cards"]) {

        NewCell *newCell = new NewCell(this);
        ui->cellLayout->addWidget(newCell, 0,  cellNumberTotal);
        connect(newCell,SIGNAL(closeThisCell(int)),this,SLOT(closeCell(int)));
        newCell->setAttribute(Qt::WA_DeleteOnClose, true);
        newCell->CellNumber = cellNumberTotal;
        QString Coowners;
        for (auto own : Card["CardOwners"]) {
            Coowners += QString::fromStdString(own) + " ";
        }

        newCell->setCoowners(Coowners);
        newCell->setColor(QString::fromStdString(Card["CardColor"]));
        newCell->setTextData(QString::fromStdString(Card["CardText"]));
        newCell->setCellName(QString::fromStdString(Card["CardName"]));
        allCellPtr.append(newCell);
        cellNumberTotal++;
    }
    DeckList::OpenedBoard->setMaxCardLabel(cellNumberTotal);
    Deck::TabIndex++;
}



void NewTab::addNewCell(QString cellText, QString cellName)
{
    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {
        if (cellNumberTotal == 4) {
            QMessageBox::warning(this, "Cant create", "Too much cards, maximum 4");
        } else {

            NewCell *newCell = new NewCell(this);
            ui->cellLayout->addWidget(newCell, 0, ui->cellLayout->columnCount());
            newCell->setStyleSheet("background-color: #FFF;");
            connect(newCell,SIGNAL(closeThisCell(int)),this,SLOT(closeCell(int)));
            newCell->setAttribute(Qt::WA_DeleteOnClose, true);
            newCell->CellNumber = cellNumberTotal;
            newCell->setColor();
            newCell->setCellName();
            newCell->setTextData(cellText);
            allCellPtr.append(newCell);
            cellNumberTotal++;
            DeckList::OpenedBoard->setMaxCardLabel(cellNumberTotal);
            QString BoardName = QString::fromStdString(DeckList::OpenedBoard->jsnBoard["Name"]);
            Database::AddNewCardToColumn(BoardName, Deck::TabIndex, cellText);
        }
    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }


}


void NewTab::closeCell(int index)
{

    if (IfUserOwnerOfBoard(Database::GetCurrentBoard(), Database::GetCurrentUser()) == 1) {
        allCellPtr[index]->close();
        for (int i=index+1; i<allCellPtr.length(); i++ ) {
            allCellPtr[i]->CellNumber--;
        }
        cellNumberTotal--;
        allCellPtr.remove(index);

        DeckList::OpenedBoard->setMaxCardLabel(cellNumberTotal);
    } else {
        QMessageBox::warning(this, "acces denied", "у тебя нет доступа для редактирования этой доски");
    }

}
