#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include "UI/w_decklist/decklist.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    static DeckList *WindowList;

private slots:
    void on_btn_SignIn_pressed();
    void on_btn_SignUp_pressed();

private:
    Ui::LoginWindow *ui;
};


#endif // LOGINWINDOW_H
