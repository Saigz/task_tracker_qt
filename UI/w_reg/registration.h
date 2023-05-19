#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QMessageBox>
#include <QRegularExpression>
#include <QDialog>

namespace Ui {
class Registration;
}

class Registration : public QDialog
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);
    ~Registration();

    void setData(QString login, QString password);


private slots:
    void on_btn_SignUp_pressed();

    void on_btn_Back_clicked();



private:
    Ui::Registration *ui;
};

#endif // REGISTRATION_H
