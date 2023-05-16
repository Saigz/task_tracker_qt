#include "database.h"

using json = nlohmann::json;


json Database::CurrentUser;
json::array_t Database::ParsedUsers;

/*
    We can just use json::array_t to store parsed info about boards and users instead of convering it to std::vector

    TODO:
    [
        Not sure about json -> std::string -> qstring convertion, may be an issue
        AddUser         -
        FindUser        -   additional function for user check in signin and signup logics
    ]

*/


void Database::ParseUserData() {
    std::cout << "Initialize parsing user data..." << std::endl;
    std::ifstream f("../task_tracker_qt/Database/users.json");
    json jsnData = nlohmann::json::parse(f);
    for (auto User : jsnData["users"]) {
        ParsedUsers.push_back(User);
    }
    std::cout << "Parsed data: " << ParsedUsers << std::endl;

}

void Database::UserDataToFile() {
    std::cout << "Initialize writing user data to file..." << std::endl;
    std::ofstream file("../task_tracker_qt/Database/users.json");
    json jsnObj;
    jsnObj["users"] = ParsedUsers;
    file << std::setw(4) << jsnObj << std::endl;
    std::cout << "Succesfully" << std::endl;
}


/*  0  not found
   -1  wrongpass
    1  successfull login  */
int Database::FindUser(QString Login, QString Password) {
    std::cout << "Trying to find user..." << std::endl;
    for (auto User : ParsedUsers) {
        std::cout << User["Login"]  << "  " << Login.toStdString() << std::endl;

        if (User["Login"] != Login.toStdString()) {

            continue;

        } else {

            if (User["Password"] == Password.toStdString()) {

                std::cout << "Find, fully matched" << std::endl;
                return 1;

            } else {

                std::cout << "Find, wrong password" << std::endl;
                return -1;

            }

        }
    }
    std::cout << "Cant find user with login: " << Login.toStdString() << std::endl;
    return 0;

}


int Database::AddUser(QString Login, QString Password) {
    int isUserExist = FindUser(Login, Password);

    if (isUserExist or isUserExist == -1) {

        std::cout << "This username is already taken" << std::endl;
        return 0;

    } else {

        json NewUser;
        NewUser["Login"] = Login.toStdString();
        NewUser["Password"] = Password.toStdString();
        ParsedUsers.push_back(NewUser);
        UserDataToFile();
        std::cout << "Succesfully added user" << std::endl;
        return 1;

    }

}

