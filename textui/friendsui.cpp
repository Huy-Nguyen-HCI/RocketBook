#include "friendsui.h"

FriendsUI::FriendsUI(QString username, AccountController* accountControl)// FriendController* friendControl)
{
    this->username=username;
    this->accountControl=accountControl;
    initialize();
    takeCommand(select(4));
}

void FriendsUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Main Menu\nPlease select one by using the arrow keys and pressing enter:");
mvprintw(3, 8, "View Friends List");
mvprintw(4, 8, "Add Friend");
mvprintw(5, 8, "Delete Friend");
mvprintw(6, 8, "Back");

mvprintw(v+2, 5, "->");
//std::to_string(v).c_str()

refresh();
}


void FriendsUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

    friendControl=new FriendController(accountControl->getPath(),accountControl->getAccountId(username));
   if(selection==1)
       displayFriends();
   else if(selection==2)
       addFriend();
   else if(selection==3)
       removeFriend();
   else if(selection==4)
       return;

   initialize();
   takeCommand(select(4));

}

void FriendsUI::displayFriends(){
    erase();
    mvprintw(0,0,"Friends:");
    QStringList friendNames= friendControl->getFriendNames();
    for(unsigned int i=0;i<friendNames.size();i++){
        mvprintw(i+1,3,friendNames.at(i).toStdString().c_str());

    }

    getch();
}

void FriendsUI::addFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username of new friend: ");
    echo();

    getstr(name);

    friendControl->addFriend(QString::fromStdString(name));
}

void FriendsUI::removeFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username friend you would like to remove: ");
    echo();

    getstr(name);

    friendControl->deleteFriend(QString::fromStdString(name));
}
