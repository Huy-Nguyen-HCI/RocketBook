#ifndef FRIENDSUI_H
#define FRIENDSUI_H

#include "screen.h"

#include "../model/accountcontroller.h"
#include "../model/rocketuser.h"


class FriendsUI: public Screen{
public:
    FriendsUI(AccountController* accountControl);// FriendController* friendControl);

  //  int run();

    QString username;
    void drawScreen(int v);
    void takeCommand(int selection);

private:
    AccountController* accountControl;
    FriendController* friendControl;
    RocketUser* user;
    void addFriend();
    void removeFriend(int index);
    int selectFriend();
    int viewFriendsProfile(int v);

};

#endif // FRIENDSUI_H
