#include "friendsui.h"

FriendsUI::FriendsUI(AccountController* accountControl)// FriendController* friendControl)
{
    user=accountControl->getUser();
    username=user->getUsername();
    this->accountControl=accountControl;
    initialize();
    options=accountControl->getUser()->controlFriend()->getFriendNames().size();
    takeCommand(select(4));
}

void FriendsUI::drawScreen(int v) {

clear();

// print the instructions for manipulating the Value object
mvprintw(0, 0, "Friends");
mvprintw(3, 8, "View Friends List");
mvprintw(4, 8, "Add Friend");
mvprintw(5, 8, "Delete Friend");
mvprintw(6, 8, "Back");

mvprintw(v+2, 5, "->");

refresh();
}


void FriendsUI::takeCommand(int selection){

    // cleanup the window and return control to bash
    endwin();

   friendControl=new FriendController(accountControl->getPath(),accountControl->getAccountId(username));
   if(selection==1){

       int chosenFriend=selectFriend(10);
       getch();
   }
   else if(selection==2)
       addFriend();
   else if(selection==3)
       removeFriend();
   else if(selection==4)
       return;

   initialize();
   takeCommand(select(4));

}




/**

void FriendsUI::displayFriends(int i){
    erase();

    QStringList friendNames= friendControl->getFriendNames();
    std::vector<std::string> friends;

    for(unsigned int j=i;j<friendNames.size();j++){
        friends.push_back(friendNames.at(j).toStdString());
    }
    for(unsigned int k=0;k<friends.size();k++)
        mvprintw(k+1,3,friends.at(k).c_str());

}
**/
void FriendsUI::addFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username of new friend: ");
    echo();

    getstr(name);

    accountControl->getUser()->controlFriend()->addFriend(QString::fromStdString(name));
}

void FriendsUI::removeFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username of friend you would like to remove: ");
    echo();

    getstr(name);

    accountControl->getUser()->controlFriend()->deleteFriend(QString::fromStdString(name));
}

//void FriendsUI::displayFriends(){
//    erase();
//    mvprintw(0,0,"Friends:");

//    QStringList friendNames= friendControl->getFriendNames();
//            //QStringList friendNames= accountControl->getUser()->controlFriend()->getFriendNames();
//    for(unsigned int i=0;i<friendNames.size();i++){
//        mvprintw(i+1,3,friendNames.at(i).toStdString().c_str());

//    }
//}

int FriendsUI::displayFriends(int v){
    erase();
    mvprintw(0,0,"Friends:");


    QStringList friendNames= friendControl->getFriendNames();
            //QStringList friendNames= accountControl->getUser()->controlFriend()->getFriendNames();
    for(unsigned int i=0;i<friendNames.size();i++){
        mvprintw(i+2,8,friendNames.at(i).toStdString().c_str());
    }

    mvprintw(v+1, 5, "->");
    refresh();

    return friendControl->getFriendNames().size();

}

int FriendsUI::selectFriend(int m){

    int max=m;

    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    int totalFriends=displayFriends(v);


   if(totalFriends<max)
       max=totalFriends;

    do {
        // draw the new screen
        refresh();
        // obtain character from keyboard
        int ch = getch();
        // operate based on input character
        switch (ch) {
        case KEY_UP:
            if(v>0) //arrow goes up
            v--;
            if(v==0) //arrow goes to bottom
                v=max;
            break;
        case KEY_DOWN:
            if(v<max+1) //arrows goes down
            v++;
            if(v==max+1) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        displayFriends(v);

    } while(continue_looping);

    return v;

}

//void FriendsUI::displayFriends(){

  //  int size=friendControl->getFriendNames().size();
