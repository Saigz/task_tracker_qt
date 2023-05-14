#include "UI\w_login\loginwindow.h"
#include "ui_loginwindow.h"
#include "UI\w_decklist\decklist.h"
#include <UI\w_reg\registration.h>

#include <QMessageBox>


LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    WindowList = new class::DeckList();
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_btn_SignIn_pressed()
{
    QString Login = ui->lineEdit_Login->text();
    QString Pass = ui->lineEdit_Password->text();


    //Input validation
    if (Login.isEmpty() or Pass.isEmpty()) {
        QMessageBox::warning(this, "Incorrect input", "Entered data is not valid, empty, or contains prohibited symbols: _ _ _ _ _ _");
    } else {

        // if db.find(login, pasw) == 1;
        if (Login == "user" and Pass == "user") {
            this->close();
            WindowList->show();

        } else {
            QMessageBox::warning(this, "Icorrect credentials", "Incorrect password or login");
        }

    }

}


void LoginWindow::on_btn_SignUp_pressed()
{
    Registration reg_window;
    reg_window.setModal(true);
    reg_window.exec();
}

