#ifndef DECK_H
#define DECK_H

#include <QMainWindow>
#include "UI/w_deck/NewTab/newtab.h"
#include <QMessageBox>
#include <QDebug>
#include "nlohmann/json.hpp"

using json = nlohmann::json;

namespace Ui {
class Deck;
}

class Deck : public QMainWindow
{
    Q_OBJECT

public:
    explicit Deck(QWidget *parent = nullptr);
    ~Deck();

    //All tabs vector
    QVector<NewTab*> allTabPtrs;

    //json board object
    json jsnBoard;

signals:
    void deck_list();

private slots:
    void on_btn_close_clicked();

    void on_btn_add_column_clicked();

    void on_btn_add_owner_clicked();

    void on_tabWidget_tabCloseRequested(int index);

private:
    Ui::Deck *ui;
    void addTab(QString ColumnName);

};

#endif // DECK_H
