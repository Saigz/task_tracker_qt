#include "registration.h"
#include "ui_registration.h"
#include "Database/database.h"

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
    int login_length = ui->lineEdit_Login->text().size();
    int pass_length = ui->lineEdit_Password->text().size();


    if (Login.isEmpty() or Password.isEmpty() or login_length < 3 or pass_length < 3) {

        QMessageBox::warning(this, "Incorrect input", "Entered data is not valid, empty, or contains prohibited symbols: _ _ _ _ _ _");

    } else {

        int SuccesfullyAdded = Database::AddUser(Login, Password);

        if (SuccesfullyAdded) {

            QMessageBox::information(this, "кайф", "Успешно зарегистрировался");
            close();

        } else {

            QMessageBox::warning(this, "печалька", "Занято, попутал ты чето");
        }
    }
}


void Registration::on_btn_Back_clicked()
{
    close();
}

