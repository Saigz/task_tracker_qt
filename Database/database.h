#ifndef DATABASE_H
#define DATABASE_H

#include "Utility.h"


typedef struct User {

    int Index;
    string Login;
    string Password;
    string USERID;
    int AdminFlag;


} User;

typedef struct Board {

    string Name;


} Board;

typedef struct Column {

    string Name;


} Column;

typedef struct Card {

    string Name;
    string Text;
    int Color;

} Card;

class Database
{
public:
    Database();

    void AddUserFromString(string Buffer);
    static void ParseUserData();
    static void UserDataToFile();
    static void RegUser(string Login, string Password);
    static string FindUser(string Login, string Password);
    static int DeleteUser(int UserIndex);

    static void ParseBoardData();
    static void BoardToFile();
    static int DeleteData(int DataIndex);
    static string FindBoardData(string Name);

};

#endif // DATABASE_H
