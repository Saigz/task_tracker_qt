#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "data/includes/json.hpp"

using json = nlohmann::json;


//--------------------------------------------------
//May be useless, delete if needed
struct User {
    std::string Login;
    std::string Password;
};

struct Column {
    std::vector<std::string> TextFields;
};

struct Board {
    std::string Name;
    std::string Type;
    std::vector<std::string> Owners;
    std::vector<Column> Columns;
};
//--------------------------------------------------





class Database {
private:

    static json CurrentUser;
    static json::array_t ParsedUsers;

    static json CurrentBoard;
    static json::array_t ParsedBoards;


public:
//---------------------user------------------------------------------

    static void ParseUserData();
    static void UserDataToFile();

    static int FindUser(QString Login, QString Password);
    static int AddUser(QString Login, QString Password);

//--------------------boards-----------------------------------------

    static void ParseBoardsData();
    static void BoardsDataToFile();

    static json FindBoard(QString Name);
    static int CreateBoard(QString Name, QString Type);
    static int DeleteBoard(QString Name);
    static json GetAllBoardForUser();

    static void ChangeBoardName(QString BoardName, QString NewBoardName);
    static void ChangeBoardType(QString BoardName, QString Type);
    static void AddOwnerToBoard(QString BoardName, QString NewOwnerLogin);

    static void AddNewColumn(QString BoardName, QString ColumnName);
    static void RenameColumn(QString BoardName, int Index, QString NewColumnName);
    static void DeleteColumn(QString BoardName, int Index);

    static void AddNewCardToColumn(QString BoardName, QString ColumnName, QString Text);


//------------------optional------------------------------------------

    static json GetParsedBoards();

    static void SetCurrentUser(json User);
    static json GetCurrentUser();

    static void SetCurrentBoard(json Board);
    static json GetCurrentBoard();

};



#endif // DATABASE_H
