#include "newcell.h"
#include "ui_newcell.h"
#include "UI/w_boardedit/boardedit.h"

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

void NewCell::setCellName(QString cellName){
    ui->cellLabel->setText(cellName);
}


void NewCell::on_deleteButton_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Delete Confirmation", "Delete This Cell?",QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes){
        emit closeThisCell(CellNumber);
    }
    //    this->close();
}


void NewCell::on_clearButton_clicked()
{
    ui->textEdit->clear();
}


void NewCell::on_editLabelButton_clicked()
{
//    OpenedBoard->close();
    BoardEdit z;
    z.setModal(true);
    z.exec();

}

