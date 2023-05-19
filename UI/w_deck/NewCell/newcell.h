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


    void setColor(QString Color = "Green");
    void setTextData(QString cellText = "Write here something!");
    void setCellName(QString cellName = "New Card");
    void setCoowners(QString Coowners);

private:
    Ui::NewCell *ui;

signals:

    void closeThisCell(int);

private slots:

    void on_deleteButton_clicked();
    void on_btn_color_clicked();
    void on_btn_coowner_clicked();
    void on_btn_position_clicked();
    void on_btn_savetext_clicked();
    void on_btn_rename_clicked();
};

#endif // NEWCELL_H
