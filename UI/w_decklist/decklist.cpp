#include "decklist.h"
#include "ui_decklist.h"
#include "createdeck.h";

DeckList::DeckList(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DeckList)
{
    ui->setupUi(this);

    QListWidgetItem *test_item = new QListWidgetItem;
    test_item->setText("test_private_item");
    ui->listWidget->insertItem(1, test_item);   // (1 - row) add item in list widget
}

DeckList::~DeckList()
{
    delete ui;
}


void DeckList::on_btn_Open_pressed()
{
    // сделать проверку в дб на приватность else выдать ошибку
    QListWidgetItem curr_item;
    curr_item = *ui->listWidget->takeItem(ui->listWidget->currentRow()); // чет вернули хз что
    curr_item.text(); //  string name of current item (надо как то его дать в некст окно)
}



void DeckList::on_btn_Create_pressed()
{
    CreateDeck window;
    window.setModal(true);
    window.exec(); // open create deck window
}



void DeckList::on_btn_Delete_pressed()
{
    // проверка на уточнение(надо сделать)
    ui->listWidget->takeItem(ui->listWidget->currentRow()); // delete current item
}



void DeckList::on_btn_Exit_pressed()
{
    close();
}

