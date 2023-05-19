#include "UI\w_login\loginwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>
#include <QStyleFactory>
#include "domain/database.h"


/*

    TODO:
    [

        btn.pressed -> btn.clicked
        jsnBoard and OpenedBoard does not affected by inner class changes

        board owner button to boardedit
        BoardEdit multi fix
        Card management
        Pictures Management
        CardColourManagament
    ]

*/

int main(int argc, char *argv[])
{



    Database::ParseBoardsData();
    Database::ParseUserData();


    //Database::AddNewCardToColumn("BIB", 3, "NewNeWnEw");
    //Database::DeleteOwnerFromBoard("BIB", "notfound");
    //Database::DeleteCardFromColumn("BIB", 0, 0);
    QApplication a(argc, argv);
    a.setStyle(QStyleFactory::create("Fusion"));
    a.setStyleSheet("QMessageBox {"
                        "background-color: Black;"
                        "font: 600 10pt Montserrat SemiBold;"
                    "}"
                    "QMessageBox QPushButton {"
                        "border: 2px solid  rgb(155, 144, 200);"
                        "border-radius: 8px;"
                        "padding-left: auto;"
                        "padding-right: auto;"
                        "color: rgb(0, 0, 0);"
                        "font: 600 10pt Montserrat SemiBold;"
                    "}"
                    "QInputDialog {"
                        "background-color: Black;"
                        "font: 600 10pt Montserrat SemiBold;"
                    "}"
                    "QInputDialog QPushButton {"
                        "border: 2px solid  rgb(155, 144, 200);"
                        "border-radius: 8px;"
                        "padding-left: auto;"
                        "padding-right: auto;"
                        "color: rgb(0, 0, 0);"
                        "font: 600 10pt Montserrat SemiBold;"
                    "}"
                    "QInputDialog QLineEdit {"
                        "border: 2px solid rgb(156, 132, 192);"
                        "border-radius: 8px;"
                        "padding-left: auto;"
                        "padding-right: auto;"
                        "color: rgb(255, 255, 255);"
                        "background-color: rgb(27, 29, 35);"
                        "font: 600 10pt Montserrat SemiBold;"
                    "}"
                    );
    LoginWindow w;
    w.show();
    return a.exec();

}
