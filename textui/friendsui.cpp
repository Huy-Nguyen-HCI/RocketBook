#include "friendsui.h"

FriendsUI::FriendsUI(QString username, AccountController* accountControl)
{
    this->username=username;
    this->accountControl=accountControl;
initialize();
run();
}

void FriendsUI::run(){

/**


    //std::vector<QString> friends=accountControl->getFriends(username);

    for(unsigned int i=0; i<friends.capacity(); i++){
        std::cout << friends.at(i).toStdString().c_str();
    }
    erase();
    refresh();


    refresh();
//AccountController.displayFriends();

    for(unsigned int i=0; i<friends.capacity(); i++){
        mvprintw(i,3,friends.at(i).toStdString().c_str());
    }
    refresh();
    getch();
    **/

}
