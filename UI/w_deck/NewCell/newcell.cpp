#include "newcell.h"
#include "ui_newcell.h"
#include "UI/w_chooselist/chooselist.h"
#include "UI/w_deck/NewCell/w_chooseposition/chooseposition.h"

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
    emit closeThisCell(CellNumber);
}


void NewCell::on_btn_color_clicked()
{
    chooselist choose_color_window;
    choose_color_window.exec();
}


void NewCell::on_btn_coowner_clicked()
{
    chooselist choose_coowner_window;
    choose_coowner_window.exec();
}



void NewCell::on_btn_position_clicked()
{
    chooseposition position_window;
    position_window.exec();
}

