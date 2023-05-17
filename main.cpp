#include "UI\w_login\loginwindow.h"
#include "Database/database.h"
#include "UI/w_deck/deck.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>


/*
    We can just use json::array_t to store parsed info about boards and users instead of convering it to std::vector  (Done)
    Not sure about json -> std::string -> qstring convertion, may be an issue

    TODO:
    [

        Input invalidation:
            Login pass:
                min 4, max 15 symbols
                only eng alphabet and this spec sybols: _ - * # $ @ & ? !
        Boards logic))))
    ]

*/

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    Deck NewDeck;
//    NewDeck.show();
//    return a.exec();

    Database::ParseBoardsData();
    Database::ParseUserData();
    QApplication a(argc, argv);
    LoginWindow w;
    w.show();
    return a.exec();

}
