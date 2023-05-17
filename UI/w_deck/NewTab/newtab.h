#ifndef NEWTAB_H
#define NEWTAB_H

#include <QWidget>
#include "UI/w_deck/NewCell/newcell.h"

namespace Ui {
class NewTab;
}

class NewTab : public QWidget
{
    Q_OBJECT

public:
    explicit NewTab(QWidget *parent = nullptr);
    ~NewTab();
    int cellNumberTotal;
    QVector<NewCell*> allCellPtr;

public slots:
    void closeCell(int);

private slots:
    void on_pushButton_clicked();
    void addNewCell(QString cellText = "", QString cellName = "Cell Name");

private:
    Ui::NewTab *ui;
};

#endif // NEWTAB_H
