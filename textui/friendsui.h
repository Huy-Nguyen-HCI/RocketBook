#ifndef FRIENDSUI_H
#define FRIENDSUI_H

#include "screen.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"


class FriendsUI: public Screen{
public:
    FriendsUI(QString username, AccountController* accountControl);// FriendController* friendControl);

  //  int run();

    QString username;
    void drawScreen(int v);
    void takeCommand(int selection);

private:
    AccountController* accountControl;
    FriendController* friendControl;
    void displayFriends();
    void addFriend();
    void removeFriend();

};

#endif // FRIENDSUI_H
