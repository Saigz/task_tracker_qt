#include "UI\w_login\loginwindow.h"
#include "Database/database.h"
#include "UI/w_deck/deck.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <QStyleFactory>


/*

    TODO:
    [

        btn.pressed -> btn.clicked
        jsnBoard and OpenedBoard does not affected by inner class changes

        Card management
        Pictures Management
        CardColourManagament
    ]

*/

int main(int argc, char *argv[])
{

    Database::ParseBoardsData();
    Database::ParseUserData();

    //Database::DeleteColumn("BIB", 1);
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    LoginWindow w;
    w.show();
    return a.exec();

}
