#ifndef DOMAIN_H
#define DOMAIN_H
#include "UI/w_reg/registration.h"
#include "data/includes/json.hpp"

using json = nlohmann::json;


int InputValidation(QString Text);

void SignUp(Ui::Registration *RegObj,  Registration *obj);

int IfUserOwnerOfBoard(json Board, json User);

int IfUserOwnerOfCard(json Board, int ColumnIndex, int CardIndex, json User);



#endif // DOMAIN_H
