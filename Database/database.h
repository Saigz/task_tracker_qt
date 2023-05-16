#ifndef DATABASE_H
#define DATABASE_H

#include <QString>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "nlohmann/json.hpp"

using json = nlohmann::json;

struct User {
    std::string Login;
    std::string Password;
};


struct Board {
    std::vector<std::string> Owners;

    //TODO

};


class Database {
private:

    static json CurrentUser;
    static json::array_t ParsedUsers;

public:

    static void ParseUserData();
    static void UserDataToFile();

    static int FindUser(QString Login, QString Password);

    static int AddUser(QString Login, QString Password);


};



#endif // DATABASE_H
