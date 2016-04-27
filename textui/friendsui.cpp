#include "friendsui.h"

FriendsUI::FriendsUI(AccountController* accountControl)// FriendController* friendControl)
{
    user=accountControl->getUser();
    username=user->getUsername();
    this->accountControl=accountControl;
    initialize();
    options=accountControl->getUser()->controlFriend()->getFriendNames().size();
    options=4;
    takeCommand(select(options));
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

       int chosenFriend=selectFriend(LINES-4);
       viewFriendsProfile(chosenFriend);

   }
   else if(selection==2)
       addFriend();
   else if(selection==3){
       removeFriend();
   }
   else if(selection==4)
       return;

   initialize();
   takeCommand(select(options));

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


int FriendsUI::displayFriends(int v){
    erase();
    mvprintw(0,0,"Select a friend's profile to view it or hit q to go back");


    QStringList friendNames= friendControl->getFriendNames();

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
        case 113: //q
            return -1;
        }

        displayFriends(v);

    } while(continue_looping);

    return v-1;

}

int FriendsUI::viewFriendsProfile(int v){
        erase();
    if(v==-1)
        return 0;


    clear();
    mvprintw(0,0,"Friend's Profile");

    QStringList friendNames= friendControl->getFriendNames();
    ProfileInfoType profile = accountControl->getUser()->controlFriend()->getFriendProfile(friendNames.at(v));
    QString fullName = "Name:   " + std::get<1>(profile);
    QString description = "Description: " + std::get<3>(profile);

    //QString username = "Username: " + accountControl->getUser()->getUsername();
    mvprintw(1,1, fullName.toStdString().c_str());
    mvprintw(2,1, description.toStdString().c_str());

    //QString description = "Description: " + accountControl->getUser()->getUsername();
    //mvprintw(2,0, description.toStdString().c_str());

    getch();
}

