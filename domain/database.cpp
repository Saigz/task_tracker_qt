#include "database.h"
#include <iterator>

using json = nlohmann::json;

//-----------------------------------------USERS----------------------------------------------
//--------------------------------------------------------------------------------------------

json Database::CurrentUser;
json::array_t Database::ParsedUsers;

json Database::CurrentBoard;
json::array_t Database::ParsedBoards;


void Database::ParseUserData() {
    std::cout << "Initialize parsing user data..." << std::endl;
    std::ifstream f("../task_tracker_qt/data/users.json");
    json jsnData = nlohmann::json::parse(f);
    for (auto User : jsnData["users"]) {
        ParsedUsers.push_back(User);
    }
    std::cout << "Parsed user data: " << ParsedUsers << std::endl;

}

void Database::UserDataToFile() {
    std::cout << "Initialize writing user data to file..." << std::endl;
    std::ofstream file("../task_tracker_qt/data/users.json");
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

//----------------------------------------BOARDS----------------------------------------------
//--------------------------------------------------------------------------------------------

void Database::ParseBoardsData() {
    std::cout << "Initialize parsing boards data..." << std::endl;
    std::ifstream f("../task_tracker_qt/data/boards.json");
    json jsnData = nlohmann::json::parse(f);
    for (auto Board : jsnData["boards"]) {
        ParsedBoards.push_back(Board);
    }
    std::cout << "Parsed boards data: " << ParsedBoards << std::endl;
}


void Database::BoardsDataToFile() {
    std::cout << "Initialize writing boards data to file..." << std::endl;
    std::ofstream file("../task_tracker_qt/data/boards.json");
    json jsnObj;
    jsnObj["boards"] = ParsedBoards;
    file << std::setw(4) << jsnObj << std::endl;
    std::cout << "Succesfully" << std::endl;
}


json Database::FindBoard(QString Name) {
    for (auto Board : ParsedBoards) {
        std::cout << Board["Name"]  << "  " << Name.toStdString() << std::endl;
        if (Board["Name"] == Name.toStdString()) {
            std::cout << "Find full match" << std::endl;
            return Board;
        }
    }
    std::cout << "Cant find this board" << std::endl;
    return 1;
}


int Database::CreateBoard(QString Name, QString Type) {
    std::cout << "Initializing board creation..." << std::endl;
    json IsNameAvailable = FindBoard(Name);
    if (IsNameAvailable == 1) {

        json NewBoard;
        NewBoard["Name"] = Name.toStdString();
        NewBoard["Type"] = Type.toStdString();
        NewBoard["Owners"].push_back(CurrentUser["Login"]);
        NewBoard["Columns"];

        ParsedBoards.push_back(NewBoard);
        BoardsDataToFile();
        std::cout << "Board creation successfull" << std::endl;
        return 1;

    }
    std::cout << "Cant create board with that name, already taken" << std::endl;
    return 0;
}


int Database::DeleteBoard(QString Name) {
    std::cout << "Board deletion initialized..." << std::endl;
    int index = 0;
    for (auto Board : ParsedBoards) {
        if (Board["Name"] == Name.toStdString()) {
            ParsedBoards.erase(ParsedBoards.begin() + index);
            BoardsDataToFile();
            std::cout << "Board successfully deleted" << std::endl;
            return 1;
        }
        index++;
    }
    std::cout << "Cant find that board, deletion cancelled" << std::endl;
    return 0;
}


json Database::GetAllBoardForUser(){
    json::array_t BoardsForUser;

    for (auto Board : ParsedBoards) {
        if (Board["Type"] == "public") {
            BoardsForUser.push_back(Board);
            continue;
        }

        for (auto User : Board["Owners"]) {
            if (User == CurrentUser["Login"]) {
                BoardsForUser.push_back(Board);
                break;
            }
        }
    }

    if (BoardsForUser.empty()) {
        return {"null"};
    } else {
        return BoardsForUser;
    }

}

void Database::ChangeBoardName(QString BoardName, QString NewBoardName)
{
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            Board["Name"] = NewBoardName.toStdString();
            BoardsDataToFile();
            return;
        }
    }
}

void Database::ChangeBoardType(QString BoardName, QString Type)
{
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            Board["Type"] = Type.toStdString();
            BoardsDataToFile();
            return;
        }
    }
}


void Database::AddNewColumn(QString BoardName, QString ColumnName)
{
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            json NewColumn;
            NewColumn["ColumnName"] = ColumnName.toStdString();
            NewColumn["Cards"];
            Board["Columns"].push_back(NewColumn);
            CurrentBoard["Columns"].push_back(NewColumn);
            BoardsDataToFile();
            return;

        }
    }
}


void Database::AddNewCardToColumn(QString BoardName, int ColumnIndex, QString Text)
{
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            if (Board["Columns"].size() < ColumnIndex) {
                std::cout << "Cant find Columns by this index" << std::endl;
                return;
            }
            int i = 0;
            for (auto & Column : Board["Columns"]) {
                if (i == ColumnIndex) {
                    json Card;
                    Card["CardName"] = "CardName";
                    Card["CardText"] = Text.toStdString();
                    Card["CardColor"] = "XXXXX";
                    for (auto Own : Board["Owners"]) {
                        Card["CardOwners"].push_back(Own);
                    }

                    Column["Cards"].push_back(Card);
                    BoardsDataToFile();
                    std::cout << "Added basic card to this column" << std::endl;
                    return;
                }
                i++;
            }
            return;
        }
    }
}

void Database::RenameColumn(QString BoardName, int Index, QString NewColumnName)
{
    int ind = 0;
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            for (auto & i : Board["Columns"]) {
                if (Index == ind) {
                    std::cout << i["ColumnName"] << "  " << NewColumnName.toStdString() << std::endl;
                    i["ColumnName"] = NewColumnName.toStdString();
                    BoardsDataToFile();
                    return;
                }
                ind++;
            }

        }
    }
}

void Database::DeleteColumn(QString BoardName, int Index) {
    int ind = 0;
    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {

            Board["Columns"].erase(Board["Columns"].begin() + Index);

            BoardsDataToFile();
            return;
            ind++;
        }

    }
}


void Database::AddOwnerToBoard(QString BoardName, QString NewOwnerLogin) {

    for (auto & Board : ParsedBoards) {
        if (Board["Name"] == BoardName.toStdString()) {
            Board["Owners"].push_back(NewOwnerLogin.toStdString());
            BoardsDataToFile();
            return;
        }
    }
}

//------------------optional------------------------------------------

json Database::GetParsedBoards() {
    return ParsedBoards;
}

void Database::SetCurrentUser(json User) {
    CurrentUser = User;
}

json Database::GetCurrentUser() {
    return CurrentUser;
}

void Database::SetCurrentBoard(json Board) {
    CurrentBoard = Board;
}

json Database::GetCurrentBoard() {
    return CurrentBoard;
}
