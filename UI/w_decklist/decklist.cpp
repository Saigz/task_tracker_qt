#include "decklist.h"
#include "ui_decklist.h"
#include "ui_deck.h"
#include "UI\w_createdeck\createdeck.h"
#include "UI\w_deck\deck.h"
#include "domain/database.h"
#include "domain/domain.h"

Deck *DeckList::OpenedBoard;

DeckList::DeckList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeckList)
{

    OpenedBoard = new Deck();
    ui->setupUi(this);

    UpdateBoards();
}


DeckList::~DeckList()
{
    delete ui;
}


void DeckList::on_btn_Open_clicked()
{
    OpenDeck(ui, this, OpenedBoard);
}

void DeckList::UpdateBoards() {

    getDeckList(ui, this);

}

void DeckList::on_btn_Create_pressed()
{
    CreateDeck create_deck_window;
    create_deck_window.setModal(true);
    create_deck_window.exec(); // open create deck window
}

void DeckList::on_btn_Delete_pressed()
{

    deleteFromDeckList(ui, this);

}

void DeckList::on_btn_Exit_pressed()
{
    close();
    emit login_window(); // back to loginwindow
}





