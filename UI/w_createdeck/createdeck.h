#ifndef CREATEDECK_H
#define CREATEDECK_H

#include <QDialog>

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

private:
    Ui::CreateDeck *ui;
};

#endif // CREATEDECK_H
