#include "UI/w_login/loginwindow.h"
#include "ui_loginwindow.h"
#include "UI/w_decklist/decklist.h"
#include <UI/w_reg/registration.h>
#include "domain/database.h"


DeckList *LoginWindow::WindowList;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    WindowList = new class::DeckList();
    ui->setupUi(this);
    connect(WindowList, &DeckList::login_window, this, &LoginWindow::show);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_btn_SignIn_pressed()
{
    QString Login = ui->lineEdit_Login->text();
    QString Password = ui->lineEdit_Password->text();

    if (((Login.length() < 4) or (Login.length() > 15) or Login.isEmpty()) or ((Password.length() < 4) or (Password.length() > 15) or Password.isEmpty()) or
        (!Password.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$"))) or (!Login.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$"))))
    {
            QMessageBox::information(this, "печалька", "Вы не правильно авторизуетесь. Минимум - 4 символа, максимум - 15. Поле должно содержать только буквы, цифры и _ * # $ @ & ? !");
    } else {

        int isUserExist = Database::FindUser(Login, Password);
        if (isUserExist == 1) {

            json User;
            User["Login"] = Login.toStdString();
            User["Password"] = Password.toStdString();
            Database::SetCurrentUser(User);

            ui->lineEdit_Login->setText("");
            ui->lineEdit_Password->setText("");

            this->close();
            WindowList->show();

        } else {

            QMessageBox::warning(this, "Icorrect credentials", "This user isn't exist or your credentials is wrong");

        }
    }
}


void LoginWindow::on_btn_SignUp_pressed()
{
    Registration reg_window;
    reg_window.setModal(true);
    reg_window.exec();
}

