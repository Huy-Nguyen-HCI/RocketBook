#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include <string>
#include "friendsui.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"
#include "../model/chatcontroller.h"
#include "../model/friendcontroller.h"

class MainMenu: public Screen
{
public:
    MainMenu(QString username, AccountController* accountControl,ChatController* chatControl);
    ~MainMenu();

    //Screens
    FriendsUI* friends;



    QString username;







    int run();
    void DrawScreen(int v);
    void changeScreen(int selection);

private:
    AccountController *accountControl;
    ChatController* chatControl;
  //  FriendController* friendControl;
};

#endif // MAINMENU_H
