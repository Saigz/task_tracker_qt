#include "UI/w_login/loginwindow.h"
#include "UI/w_decklist/decklist.h"
#include <UI/w_reg/registration.h>
#include "Database/database.h"

#include <QMessageBox>
#include <QRegularExpressionValidator>
#include "ui_loginwindow.h"

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
    QString Pass = ui->lineEdit_Password->text();

    //Needs proper input validation
    if (Login.isEmpty() or Pass.isEmpty()) {

        QMessageBox::warning(this, "Incorrect input", "Entered data is not valid, empty, or contains prohibited symbols: _ _ _ _ _ _");

    } else {

        int isUserExist = Database::FindUser(Login, Pass);
        if (isUserExist == 1) {

            json User;
            User["Login"] = Login.toStdString();
            User["Password"] = Pass.toStdString();
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

