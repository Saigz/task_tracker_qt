#ifndef DECK_H
#define DECK_H

#include <QMainWindow>
#include "UI/w_deck/NewTab/newtab.h"
#include <QMessageBox>
#include <iostream>
#include <string>
#include <Qt>
#include <QString>
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


    void addTab(QString ColumnName);


    void setInfoLabels(QString Name, QString Type, QString Owners);
    void setMaxCardLabel(int Count);
    void setBoardName(QString Name);
    void setBoardPrivacyType(QString);
    void addBoardOwner(QString);

signals:
    void deck_list();

private slots:

    void on_btn_add_column_clicked();

    void on_tabWidget_tabCloseRequested(int index);

    void on_btn_back_clicked();

    void on_btn_edit_clicked();

    void on_btn_rename_tab_clicked();

private:
    Ui::Deck *ui;

};

#endif // DECK_H
