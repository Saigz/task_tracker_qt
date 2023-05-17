#include "createdeck.h"
#include "ui_createdeck.h"
#include "Database/database.h"
#include "UI\w_decklist\decklist.h"
#include "ui_decklist.h"
#include "UI/w_login/loginwindow.h"

#include <QRegularExpression>
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
    QString Name = ui->lineEdit_Name->text(); // name string
    QString Type;

    if (ui->radio_Private->isChecked()) {
        Type = "private";
    } else if (ui->radio_Public->isChecked()) {
        Type = "public";
    }

    if (Name.isEmpty() or (!Name.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$")))) {
        QMessageBox::warning(this, "govno nabral", "иди нахуй дебил");
    } else {

        int isBoardNameAvailable = Database::CreateBoard(Name, Type);
        if (isBoardNameAvailable) {
            QMessageBox::warning(this, "yspex", "norm");
            close();
        } else if (isBoardNameAvailable == 0) {
            QMessageBox::warning(this, "govno nabral", "иди нахуй дебил");
        }

    }

    LoginWindow::WindowList->UpdateBoards();


}


void CreateDeck::on_btn_back_clicked()
{
    close();
}

