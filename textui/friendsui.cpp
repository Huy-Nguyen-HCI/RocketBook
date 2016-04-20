#include "friendsui.h"

FriendsUI::FriendsUI(QString username, AccountController* accountControl)
{
    this->username=username;
    this->accountControl=accountControl;
initialize();
run();
}

void FriendsUI::run(){




    std::vector<QString> friends=accountControl->getFriends(username);
    erase();
    refresh();



    char name[80], pass[80];
    mvprintw(2,0,"Enter Password: ");

    getstr(pass);
    refresh();
//AccountController.displayFriends();

    for(unsigned int i=0; i<friends.capacity(); i++){
        mvprintw(i,3,friends.at(i).toStdString().c_str());
    }
    refresh();


}
