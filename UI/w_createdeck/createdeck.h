#ifndef CREATEDECK_H
#define CREATEDECK_H

#include <QDialog>
#include <QRegularExpression>
#include <QMessageBox>


namespace Ui {
class CreateDeck;
}

class CreateDeck : public QDialog
{
    Q_OBJECT

public:
    explicit CreateDeck(QWidget *parent = nullptr);
    ~CreateDeck();

private slots:
    void on_btn_Create_pressed();

    void on_btn_back_clicked();

private:
    Ui::CreateDeck *ui;
};

#endif // CREATEDECK_H
