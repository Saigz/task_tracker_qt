#include "database.h"

User Database::CurrentUser;
std::vector<User> Database::ParsedUsers;


void Database::ParseUserData() {

    std::ifstream f("../task_tracker_qt/Database/users.json");
    nlohmann::json jsnData = nlohmann::json::parse(f);

    for (auto jsnUser : jsnData["users"]) {
        User User;
        User.Login = jsnUser["Login"];
        User.Password = jsnUser["Password"];
        ParsedUsers.push_back(User);

    }
}

void Database::UserToFile() {
    nlohmann::json jsnObj;
    nlohmann::json::array_t jsnArray;


    for (auto User : ParsedUsers) {
        nlohmann::json jsnUser;
        jsnUser["Login"] = User.Login;
        jsnUser["Password"] = User.Password;
        jsnArray.push_back(jsnUser);
    }

    jsnObj["users"] = jsnArray;

    std::cout << jsnObj;
}


void Database::FindUser() {


}


void Database::AddUser() {


}

