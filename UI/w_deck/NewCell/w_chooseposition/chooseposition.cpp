#include "chooseposition.h"
#include "ui_chooseposition.h"

chooseposition::chooseposition(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooseposition)
{
    ui->setupUi(this);
}

chooseposition::~chooseposition()
{
    delete ui;
}

void chooseposition::on_pushButton_clicked()
{
    close();
}

