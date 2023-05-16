#ifndef DECKLIST_H
#define DECKLIST_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <vector>

namespace Ui {
class DeckList;
}

class DeckList : public QMainWindow
{
    Q_OBJECT

public:
    explicit DeckList(QWidget *parent = nullptr);
    ~DeckList();

    void UpdateBoards();

private slots:
    void on_btn_Open_pressed();

    void on_btn_Create_pressed();

    void on_btn_Delete_pressed();

    void on_btn_Exit_pressed();

private:
    Ui::DeckList *ui;
};

#endif // DECKLIST_H
