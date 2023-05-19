#include "UI/w_login/loginwindow.h"
#include "ui_loginwindow.h"
#include "UI/w_decklist/decklist.h"
#include <UI/w_reg/registration.h>
#include "domain/database.h"
#include "domain/domain.h"


DeckList *LoginWindow::WindowList;

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    WindowList = new class::DeckList();
    reg_window = new Registration();

    ui->setupUi(this);

    connect(WindowList, &DeckList::login_window, this, &LoginWindow::show);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}


void LoginWindow::on_btn_SignIn_pressed()
{
    SignIn(ui, this, WindowList);
}


void LoginWindow::on_btn_SignUp_pressed()
{
    reg_window->setData(ui->lineEdit_Login->text(), ui->lineEdit_Password->text());
    reg_window->exec();
}

