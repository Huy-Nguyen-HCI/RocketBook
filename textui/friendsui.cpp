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

        int chosenFriend=selectFriend();
        if(chosenFriend!=-1)
            viewFriendsProfile(chosenFriend);
    }
    else if(selection==2)
        addFriend();
    else if(selection==3){
        int chosenFriend=selectFriend();
        if(chosenFriend!=-1)
            removeFriend(chosenFriend);
    }
    else if(selection==4)
        return;

   initialize();
   takeCommand(select(options));

}


void FriendsUI::addFriend(){
    erase();
    char name[80];

    mvprintw(1,0,"Enter Username of new friend: ");
    echo();

    getstr(name);

    if(accountControl->getUser()->controlFriend()->addFriend(QString::fromStdString(name)))
       mvprintw(LINES-2,2, "Friend added!");
    else
       mvprintw(LINES-2,2, "Username does not exist or you are already friends.");
    getch();

}

void FriendsUI::removeFriend(int index){
    QStringList friendNames= friendControl->getFriendNames();
    QString name=friendNames.at(index);

    mvprintw(LINES-2,2,"Press enter to confirm friend removal");
    noecho();
    cbreak();
    if(getch()==10){
        endwin();

        if(accountControl->getUser()->controlFriend()->deleteFriend(name))
            mvprintw(LINES-2,2, "Friend removed.");
        else
            endwin();
    }
}



int FriendsUI::selectFriend(){

    bool scrolling=true;
    int offset=0;
    int row, max;

    while(scrolling){
    erase();
    mvprintw(0,0, "Friends: Press enter to select friend");

    row=3;
    mvprintw(row, 5, "->");

    QStringList friendNames= friendControl->getFriendNames();

    max=offset+15;
    if(friendNames.size()<offset+15)
        max=friendNames.size();

    for (unsigned int i = offset; i < max; i++) {
        mvprintw(row,8,friendNames.at(i).toStdString().c_str());
        row++;
    }

    int ch= getch();
        if(ch==KEY_DOWN && (max!=(offset+1)))//ch==258 || KEY_DOWN || !((wholeScrapbook.size()-5)>offset)) //259 and 259 enables scrolling
            offset++;
        else if(ch==KEY_UP && offset>0)//ch==259 || KEY_UP || offset>0)
            offset--;
        else if(ch==KEY_UP);
        else if(ch==KEY_DOWN);
        else if(ch==10)//enter key
            scrolling=false;
        else
            return -1;

    }
    return offset;

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
    mvprintw(1,1, fullName.toStdString().c_str());
    mvprintw(2,1, description.toStdString().c_str());


    getch();
}
