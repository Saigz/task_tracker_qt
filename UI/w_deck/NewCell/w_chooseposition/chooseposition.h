#ifndef CHOOSEPOSITION_H
#define CHOOSEPOSITION_H

#include <QDialog>

namespace Ui {
class chooseposition;
}

class chooseposition : public QDialog
{
    Q_OBJECT

public:
    explicit chooseposition(QWidget *parent = nullptr);
    ~chooseposition();

private slots:
    void on_pushButton_clicked();

private:
    Ui::chooseposition *ui;
};

#endif // CHOOSEPOSITION_H
