#ifndef DECK_H
#define DECK_H

#include <QMainWindow>

namespace Ui {
class Deck;
}

class Deck : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deck(QWidget *parent = nullptr);
    ~Deck();

signals:
    void deck_list();

private slots:
    void on_btn_close_clicked();

private:
    Ui::Deck *ui;
};

#endif // DECK_H
