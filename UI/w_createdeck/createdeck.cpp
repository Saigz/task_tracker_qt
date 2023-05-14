#include "createdeck.h"
#include "ui_createdeck.h"

#include <QMessageBox>

CreateDeck::CreateDeck(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateDeck)
{
    ui->setupUi(this);
}

CreateDeck::~CreateDeck()
{
    delete ui;
}


void CreateDeck::on_btn_Create_pressed()
{
    QString name = ui->lineEdit_Name->text(); // name string

    if (name == "") { // проверка в дб что имя не занято (должна быть еще проверка чтобы не было без имени)
        // добавление в дб (надо сделать)

        close();
    } else {
        QMessageBox::warning(this, "печалька", "Занято или не выбран тип приватности");
    }
}

