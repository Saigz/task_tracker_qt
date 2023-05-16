#include "UI\w_login\loginwindow.h"
#include "Database/database.h"


#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[])
{
    Database::ParseUserData();
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();

}
