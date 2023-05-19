#include "domain.h"

#include "domain/database.h"
#include "UI/w_reg/registration.h"
#include "ui_cell.h"
#include "ui_newcell.h"
#include "ui_chooselist.h"
#include "ui_chooseposition.h"
#include "ui_decklist.h"
#include "ui_deck.h"
#include "ui_newtab.h"
#include "ui_boardedit.h"
#include "ui_createdeck.h"
#include "ui_loginwindow.h"
#include "ui_registration.h"

void deleteFromDeckList(Ui::DeckList *ui, DeckList *obj) {
    if (ui->listWidget->count() == 0) {
        QMessageBox::warning(obj, "No boards left", "You have no boards, try to create some or ask somebody for access");
    } else {
        QString Text = ui->listWidget->currentItem()->text().split(" ").at(0);
        Text.chop(2);
        Text.remove(0, 1);
        std::cout << Text.toStdString();
        Database::DeleteBoard(Text);
        ui->listWidget->takeItem(ui->listWidget->currentRow()); // delete current item
    }
}

void getDeckList(Ui::DeckList *ui, DeckList *obj) {
    ui->listWidget->clear();
    for (auto Board : Database::GetParsedBoards()) {

        QString OwnersStr;
        for (auto Owner : Board["Owners"]) {
            OwnersStr += Owner.get<std::string>() + ", ";
        }
        OwnersStr.chop(2);
        QString Text = (Board["Name"].dump() + ", " + Board["Type"].get<std::string>() + ", Owners: ").c_str();
        Text += OwnersStr;
        QListWidgetItem *test_item = new QListWidgetItem;
        test_item->setText(Text);
        ui->listWidget->insertItem(0, test_item);
    }
}

void OpenDeck(Ui::DeckList *ui, DeckList *obj, Deck *next_window) {
    QListWidgetItem curr_item;
    curr_item = *ui->listWidget->item(ui->listWidget->currentRow());
    QString BoardName = curr_item.text().split(" ").at(0);
    BoardName.chop(2);
    BoardName.remove(0, 1);


    next_window = new Deck();
    json Board = Database::FindBoard(BoardName);
    next_window->jsnBoard = Board;
    Database::SetCurrentBoard(Board);


    QString BoardOwners;
    for (auto Owners : Board["Owners"]) {
        BoardOwners += QString::fromStdString(Owners) + ", ";
    }

    next_window->setInfoLabels(QString::fromStdString(Board["Name"]), QString::fromStdString(Board["Type"]), BoardOwners);
    next_window->initTabs();

    obj->close();
    next_window->show();
}

int InputValidation(QString Text) {

    QRegularExpression QRegExp("^[0-9a-zA-Z_*#$@&?!]+$");
    if (Text.isEmpty() or !Text.contains(QRegExp) or (Text.length() < 4) or (Text.length() > 15)) {
        return 0;
    } else {
        return 1;
    }

}

void SignIn(Ui::LoginWindow *ui, LoginWindow *obj, DeckList *next_window) {
    QString Login = ui->lineEdit_Login->text();
    QString Password = ui->lineEdit_Password->text();

    if (((Login.length() < 4) or (Login.length() > 15) or Login.isEmpty()) or ((Password.length() < 4) or (Password.length() > 15) or Password.isEmpty()) or
        (!Password.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$"))) or (!Login.contains(QRegularExpression("^[0-9a-zA-Z_*#$@&?!]+$"))))
    {
        QMessageBox::information(obj, "печалька", "Вы не правильно авторизуетесь. Минимум - 4 символа, максимум - 15. Поле должно содержать только буквы, цифры и _ * # $ @ & ? !");
    } else {

        int isUserExist = Database::FindUser(Login, Password);
        if (isUserExist == 1) {

            json User;
            User["Login"] = Login.toStdString();
            User["Password"] = Password.toStdString();
            Database::SetCurrentUser(User);

            ui->lineEdit_Login->setText("");
            ui->lineEdit_Password->setText("");

            obj->close();
            next_window->show();

        } else {

            QMessageBox::warning(obj, "Icorrect credentials", "obj user isn't exist or your credentials is wrong");

        }
    }
}

void SignUp(Ui::Registration *ui, Registration *obj)
{

    QString Login = ui->lineEdit_Login->text();
    QString Password = ui->lineEdit_Password->text();

    if (Login.isEmpty() or Password.isEmpty()) {

        QMessageBox::warning(obj, "Incorrect input", "Entered data is not valid, empty, or contains prohibited symbols: _ _ _ _ _ _");

    } else {

        if (InputValidation(Login) == 0 or InputValidation(Password) == 0) {
            QMessageBox::information(obj, "печалька", "Вы не правильно регистрируетесь. Минимум - 4 символа, максимум - 15. Поле должно содержать только буквы, цифры и _ * # $ @ & ? !");
        }
        else {
            int isSuccesfullyAdded = Database::AddUser(Login, Password);
            if (isSuccesfullyAdded) {
                QMessageBox::information(obj, "кайф", "Успешно зарегистрировался");
                obj->close();
            } else {
                QMessageBox::warning(obj, "печалька", "Занято, попутал ты чето");
            }
        }
    }
}

int IfUserOwnerOfBoard(json Board, json User)
{

    if (Board["Type"] == "private") {
        for (auto Owner : Board["Owners"]) {
            std::cout << User <<  "   " << Owner << std::endl;
            if (User["Login"] == Owner) {
                std::cout << "User is owner" << std::endl;
                return 1;
            }
        }
        return 0;
    } else if (Board["Type"] == "public") {
        return 1;
    }

}

int IfUserOwnerOfCard(json Board, int ColumnIndex, int CardIndex, json User)
{
    if (IfUserOwnerOfBoard(Board, User) == 0) {
        for (auto cardOwn : Board["Columns"][ColumnIndex]["Cards"][CardIndex]["CardOwners"]) {
            if (cardOwn == User["Login"]) {
                return 1;
            }
        }
        return 0;
    } else {
        return 1;
    }
}
