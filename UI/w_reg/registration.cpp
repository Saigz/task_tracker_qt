#include "registration.h"
#include "ui_registration.h"
#include "domain/domain.h"

Registration::Registration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Registration)
{
    ui->setupUi(this);

}

Registration::~Registration()
{
    delete ui;
}

void Registration::setData(QString login, QString password) {
    ui->lineEdit_Login->setText(login);
    ui->lineEdit_Password->setText(password);
}


void Registration::on_btn_SignUp_pressed()
{
    SignUp(ui, this);
}

void Registration::on_btn_Back_clicked()
{
    close();
}

