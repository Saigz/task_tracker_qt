#include "domain.h"

#include "domain/database.h"
#include "UI/w_reg/registration.h"
#include "ui_registration.h"

int InputValidation(QString Text) {

    QRegularExpression QRegExp("^[0-9a-zA-Z_*#$@&?!]+$");
    if (Text.isEmpty() or !Text.contains(QRegExp) or (Text.length() < 4) or (Text.length() > 15)) {
        return 0;
    } else {
        return 1;
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
