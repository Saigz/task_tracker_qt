#include "chooselist.h"
#include "ui_chooselist.h"

chooselist::chooselist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chooselist)
{
    ui->setupUi(this);
}

chooselist::~chooselist()
{
    delete ui;
}

void chooselist::on_btn_close_clicked()
{
    close();
}


void chooselist::on_btn_choose_clicked()
{
    QListWidgetItem curr_item;
    curr_item = *ui->listWidget->item(ui->listWidget->currentRow());
    QString curr_item_string = curr_item.text().split(" ").at(0);
    curr_item_string.chop(2);
    curr_item_string.remove(0, 1);

    close();
}

