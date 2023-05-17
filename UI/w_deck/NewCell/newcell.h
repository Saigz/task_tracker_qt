#ifndef NEWCELL_H
#define NEWCELL_H

#include <QWidget>
#include <QMessageBox>

namespace Ui {
class NewCell;
}

class NewCell : public QWidget
{
    Q_OBJECT

public:
    explicit NewCell(QWidget *parent = nullptr);
    ~NewCell();
    int CellNumber;
    QString getTextData();
    QString getCellName();


    void setTextData(QString cellText);
    void setCellName(QString cellName);

private:
    Ui::NewCell *ui;

signals:
    void closeThisCell(int);
private slots:
    void on_clearButton_clicked();
    void on_deleteButton_clicked();
};

#endif // NEWCELL_H
