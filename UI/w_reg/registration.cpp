#include "registration.h"
#include "ui_registration.h"

#include <QMessageBox>

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

void Registration::on_btn_SignUp_pressed()
{
    QString Login = ui->lineEdit_Login->text();
    QString Password = ui->lineEdit_Password->text();


    //db.find(login, pass)

    if (Login.isEmpty() or Password.isEmpty()) {

        QMessageBox::warning(this, "Invalid input", "wrong syntax"); // if login&&pass not found
    } else {

        if (Login != "user") {
            // отправить проверку в дб + занести в дб
            QMessageBox::information(this, "кайф", "Успешно зарегистрировался"); // if login&&pass not found

        } else {

            QMessageBox::warning(this, "печалька", "Занято, попутал ты чето"); // if login&&pass found
        }
    }

}


void Registration::on_btn_Back_clicked()
{
    close();
}

