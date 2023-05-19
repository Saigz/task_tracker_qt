#include "newcell.h"
#include "ui_newcell.h"

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

