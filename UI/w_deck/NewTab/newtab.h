#ifndef NEWTAB_H
#define NEWTAB_H

#include <QWidget>
#include "UI/w_deck/NewCell/newcell.h"
#include "QTabWidget"

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

    void initCells();

public slots:
    void closeCell(int);
    void addNewCell(QString cellText = "CellText", QString cellName = "Cell Name");

private slots:
    void on_pushButton_clicked();

private:
    Ui::NewTab *ui;
};

#endif // NEWTAB_H
