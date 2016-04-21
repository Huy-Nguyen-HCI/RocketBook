#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include <string>
#include "friendsui.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"
#include "../model/chatcontroller.h"
#include "../model/friendcontroller.h"
#include "../model/rocketuser.h"
#include "postui.h"
#include "chatui.h"

class MainMenu: public Screen
{
public:
    MainMenu(AccountController* accountControl);
    ~MainMenu();

    //Screens
    FriendsUI* friends;
    ChatUI* chats;
    PostUI* post;


    void drawScreen(int v);
    void changeScreen(int selection);

private:
    AccountController *accountControl;
    RocketUser* user;
};

#endif // MAINMENU_H
