#ifndef DECKLIST_H
#define DECKLIST_H

#include "UI\w_deck\deck.h"
#include <QMainWindow>
#include <QListWidgetItem>
#include <vector>
#include "UI/w_deck/deck.h"

namespace Ui {
class DeckList;
}

class DeckList : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckList(QWidget *parent = nullptr);
    ~DeckList();
    static Deck *WindowDeck;


    static Deck *OpenedBoard;
    void UpdateBoards();

signals:
    void login_window();

private slots:

    void on_btn_Create_pressed();

    void on_btn_Delete_pressed();

    void on_btn_Exit_pressed();

    void on_btn_Open_clicked();

private:
    Ui::DeckList *ui;
};

#endif // DECKLIST_H
