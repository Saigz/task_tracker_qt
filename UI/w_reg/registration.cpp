#include "registration.h"
#include "ui_registration.h"
#include "Database/database.h"

#include <QMessageBox>
#include <QRegularExpression>

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

    //std::regex pattern("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]");
    //bool hasLetters = Login.contains(QRegularExpression("[A-Za-z]"));
    //bool hasDigits = Login.contains(QRegularExpression("\\d"));
    //bool hasSpecialChars = Login.contains(QRegularExpression("[-_*#$@&?!]"));

    if (Login.isEmpty() or Password.isEmpty()) {

        QMessageBox::warning(this, "Incorrect input", "Entered data is not valid, empty, or contains prohibited symbols: _ _ _ _ _ _");

    } else {
        if (((Login.length() < 4) or (Login.length() > 15)) or ((Password.length() < 4) or (Password.length() > 15)) or
            (!Password.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$"))) or (!Login.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$")))) {
            QMessageBox::information(this, "печалька", "Вы не правильно регистрируетесь. Минимум - 4 символа, максимум - 15. Поле должно содержать только буквы, цифры и _ * # $ @ & ? !");
        }
        else {
            int SuccesfullyAdded = Database::AddUser(Login, Password);
            if (SuccesfullyAdded) {
                QMessageBox::information(this, "кайф", "Успешно зарегистрировался");
            } else {
                QMessageBox::warning(this, "печалька", "Занято, попутал ты чето");
            }
        }
    }
}
// _-*#$@&?!     (!Password.contains(QRegularExpression("^[0-9a-zA-Z]+$"))) or (!Login.contains(QRegularExpression("^[0-9a-zA-Z]+$")))


void Registration::on_btn_Back_clicked()
{
    close();
}

