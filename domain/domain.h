#ifndef DOMAIN_H
#define DOMAIN_H
#include "UI/w_reg/registration.h"
#include "UI/w_login/loginwindow.h"
#include "UI/w_decklist/decklist.h"
#include "UI/w_deck/deck.h"
#include "UI/w_deck/NewCell/newcell.h"
#include "UI/w_deck/NewCell/w_chooseposition/chooseposition.h"
#include "UI/w_deck/NewTab/newtab.h"
#include "UI/w_createdeck/createdeck.h"
#include "UI/w_chooselist/chooselist.h"
#include "UI/w_boardedit/boardedit.h"
#include "data/includes/json.hpp"

using json = nlohmann::json;

void deleteFromDeckList(Ui::DeckList *ui, DeckList *obj);

void getDeckList(Ui::DeckList *ui, DeckList *obj);

void OpenDeck(Ui::DeckList *ui, DeckList *obj, Deck *next_window);

int InputValidation(QString Text);

void SignIn(Ui::LoginWindow *ui, LoginWindow *obj, DeckList *next_window);

void SignUp(Ui::Registration *RegObj,  Registration *obj);

int IfUserOwnerOfBoard(json Board, json User);

int IfUserOwnerOfCard(json Board, int ColumnIndex, int CardIndex, json User);



#endif // DOMAIN_H
