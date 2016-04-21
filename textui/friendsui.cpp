#include "friendsui.h"

FriendsUI::FriendsUI(QString username, AccountController* accountControl, FriendController* friendControl)
{
    this->username=username;
    this->accountControl=accountControl;
    this->friendControl=friendControl;
    initialize();
    takeCommand(run());
}

int FriendsUI::run(){

    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    DrawScreen(v);

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
                v=4;
            break;
        case KEY_DOWN:
            if(v<5) //arrows goes down
            v++;
            if(v==5) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        DrawScreen(v);

    } while(continue_looping);

    return v;

}


void FriendsUI::DrawScreen(int v) {

// temporary display string for storing the value
// of the displayed Value object.
std::string display;

// clear screen return cursor to (0,0)
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

    //std::cout << "exiting main\n";

   if(selection==1)
       displayFriends();
   else if(selection==2)
       addFriend();
   else if(selection==3)
       removeFriend();
   else if(selection==4)
       return;

   initialize();
   takeCommand(run());

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
    //accountcontroller.getuser.addfriend

    friendControl->addFriend(QString::fromStdString(name));



}

void FriendsUI::removeFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username friend you would like to remove: ");
    echo();

    getstr(name);
    //accountcontroller.getuser.addfriend

    friendControl->deleteFriend(QString::fromStdString(name));



}
