#include "database.h"

#include "Utility.h"


Database::Database()
{

}

/*=============================================USER====================================================================
 =====================================================================================================================*/
int Database::AmountOfAllUsers;
int Database::AmountOfAllBoards;
vector <User> Database::ParsedUserData;
vector <Board> Database::ParsedBoardData;

vector <Column> Database::BoardColumn;
vector <Card> Database::ColumnCard;

void Database::ParseUserData() {
    string Buffer;
    fstream File("../USERS.txt", fstream::in);

    getline(File, Buffer);
    AmountOfAllUsers = atoi(Buffer.c_str());

    while (getline(File, Buffer)) {
        stringstream StringStream(Buffer);
        User User;

        StringStream >> User.Index;
        StringStream >> User.Login;
        StringStream >> User.Password;
        StringStream >> User.USERID;
        StringStream >> User.AdminFlag;

        ParsedUserData.push_back(User);
    }
    File.close();
}



void Database::UserDataToFile() {
    fstream USERDATA("../USERS.txt", fstream::out);
    USERDATA << AmountOfAllUsers << '\n';
    for (auto &User : ParsedUserData) {
        USERDATA << User.Index << "    " << User.Login << "    " << User.Password << "    " << User.USERID << "    " \
        << User.AdminFlag << '\n';
    }
    USERDATA.close();
}


void Database::RegUser(string Login, string Password) {
    User NewUser;
    NewUser.Index = AmountOfAllUsers+1;
    NewUser.Login = std::move(Login);
    NewUser.Password = std::move(Password);
    NewUser.USERID = IDCreator(AmountOfAllUsers+1);
    NewUser.AdminFlag = 0;


    ParsedUserData.push_back(NewUser);
    AmountOfAllUsers++;
    UserDataToFile();
}


string Database::FindUser(string Login, string Password) {
    string Buffer;
    for (auto &User : ParsedUserData) {
        if (User.Login == Login and User.Password == Password) {

            Buffer += to_string(User.Index); Buffer += "    ";
            Buffer += User.Login; Buffer += "    ";
            Buffer += User.Password; Buffer += "    ";
            Buffer += User.USERID; Buffer += "    ";
            Buffer += to_string(User.AdminFlag);
            return Buffer;
        }
        else if (User.Login == Login and User.Password != Password) {

            return "WRONGPASS";
        }
    }
    //strcpy(OutputStr, "NOTFOUND");
    return "NOTFOUND";
}

int Database::DeleteUser(int UserIndex) {
    int Index = 0, IsDeleteSuccessful = 0;
    for (auto &User : ParsedUserData) {
        if (User.Index == UserIndex) {
            ParsedUserData.erase(ParsedUserData.begin() + Index);
            IsDeleteSuccessful = 1;
            break;
        }
        Index++;
    }
    Index = 0;
    if (IsDeleteSuccessful) {
        AmountOfAllUsers--;
        for (auto &User : ParsedUserData) {
            User.Index = Index;
            Index++;
        }
        UserDataToFile();
        return 1;
    }
    return 0;
}

/*===============================================BOARDS DATA===========================================================
 =====================================================================================================================*/


int Database::DeleteData(int DataIndex) {
    int Index = 0, IsDeleteSuccessful = 0;
    for (auto &Data : ParsedBoardData) {
        if (Data.Index == DataIndex) {
            ParsedBoardData.erase(ParsedBoardData.begin() + Index);
            IsDeleteSuccessful = 1;
            break;
        }
        Index++;
    }
    Index = 0;
    if (IsDeleteSuccessful) {
        AmountOfAllBoards--;
        for (auto &Data : ParsedBoardData) {
            Data.Index = Index;
            Index++;
        }
        ReservedDataToFile();
        return 1;
    }
    return 0;
}

void Database::BoardToFile() {
    fstream BOARDDATA("../BOARDS.txt", fstream::out);
    BOARDDATA << AmountOfAllBoards << '\n';
    for (auto &Board : ParsedBoardData) {
        BOARDDATA << Board.name << '\n';
    }
    BOARDDATA.close();
}

void Database::ParseBoardData() {
    string Buffer;
    fstream File("../BOARDS.txt", fstream::in);

    getline(File, Buffer);
    AmountOfAllBoards = atoi(Buffer.c_str());

    while (getline(File, Buffer)) {
        stringstream StringStream(Buffer);
        Board Board;

        StringStream >> Board.Name;

        ParsedBoardData.push_back(Name);
    }
    File.close();
}

string Database::FindBoardData(string Name) {
    string Buffer;
    for (auto &Board : ParsedBoardData) {
        if (Board.Name == Name) {

            Buffer += to_string(Data.Index); Buffer += "    ";
            Buffer += Data.Type; Buffer += "    ";
            Buffer += Data.Date; Buffer += "    ";
            Buffer += Data.Place; Buffer += "    ";
            Buffer += Data.User;
            return Buffer;
        }
    }
    //strcpy(OutputStr, "NOTFOUND");
    return "NOTFOUND";
}

void Database::AddNewReservation(string Type, string Date, string Place, string User) {
    ReservedData NewData;

    NewData.Index = AmountOfAllReserved+1;
    NewData.Type = std::move(Type);
    NewData.Date =  std::move(Date);
    NewData.Place =  std::move(Place);
    NewData.User =  std::move(User);


    ParsedReservedData.push_back(NewData);
    AmountOfAllReserved++;
    ReservedDataToFile();
}

string Database::Reserve(string Login, int ReserveIndex) {
    if (ReserveIndex > ParsedReservedData.capacity()) {
        return "NOTFOUND";
    }
    if (FindUser(Login, "KOCTbILb") != "NOTFOUND") {
        if (ParsedReservedData[ReserveIndex].User == Login) {
            return "ALREADY RESERVED";
        }
        if (ParsedReservedData[ReserveIndex].User != "NONE" and ParsedReservedData[ReserveIndex].User != Login) {
            return "RESERVED BY ANOTHER USER";
        }
        ParsedReservedData[ReserveIndex].User = Login;
        ReservedDataToFile();
        return Login + " SUCCESSFULLY RESERVED " + to_string(ReserveIndex) + " SLOT";
    }
    return "NOTFOUND";
}
