#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "nlohmann/json.hpp"


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
    static User CurrentUser;
    static std::vector<User> ParsedUsers;

public:

    static void ParseUserData();
    static void UserToFile();

    static void FindUser();
    static void AddUser();




};



#endif // DATABASE_H
