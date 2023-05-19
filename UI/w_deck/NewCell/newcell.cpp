#include "newcell.h"
#include "ui_newcell.h"
#include "UI/w_chooselist/chooselist.h"

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
    choose_color_window.setModal(true);
    choose_color_window.exec();
}


void NewCell::on_btn_coowner_clicked()
{
    chooselist choose_coowner_window;
    choose_coowner_window.setModal(true);
    choose_coowner_window.exec();
}

