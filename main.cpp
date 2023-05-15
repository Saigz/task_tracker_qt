#include "UI\w_login\loginwindow.h"
#include "Database/database.h"


#include <QApplication>
#include <iostream>
#include <fstream>
#include <string>


int main(int argc, char *argv[])
{
        QApplication a(argc, argv);
        LoginWindow w;
        w.show();

        return a.exec();


//    j["Login"] = Us.Login;
//    j["Password"] = Us.Password;

//    std::cout << j << std::endl;

//    std::string serializedStr = j.dump(); // {"Login": "User", "Password": "123"}

//    User p1{};
//    nlohmann::json j1 = nlohmann::json::parse(serializedStr);
//    p1.Login = j1["Login"].get<std::string>();
//    p1.Password = j1["Password"].get<std::string>();

//    std::cout << p1.Login << std::endl << p1.Password;
//    return 1;

//    Database::ParseUserData();
//    Database::UserToFile();


//    return 1;
}
