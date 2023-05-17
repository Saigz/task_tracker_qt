#include "deck.h"
#include "ui_deck.h"
#include <UI\w_cell\cell.h>

Deck::Deck(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Deck)
{
    ui->setupUi(this);
}

Deck::~Deck()
{
    delete ui;
}

void Deck::on_btn_close_clicked()
{
    close();
    emit deck_list();
}

//Cell cell_window;
//cell_window.setModal(true);
//cell_window.exec();
