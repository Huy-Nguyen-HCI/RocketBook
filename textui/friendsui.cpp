#include "friendsui.h"

FriendsUI::FriendsUI(QString username)
{
    this->username=username;
initialize();
run();
}

void FriendsUI::run(){



    controller->displayFriends(username);


    char name[80], pass[80];
    mvprintw(2,0,"Enter Password: ");

    getstr(pass);

//AccountController.displayFriends();



}
