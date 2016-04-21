#include "mainmenu.h"

MainMenu::MainMenu(QString username, AccountController* accountControl)
{
    this->accountControl=accountControl;
    //this->chatControl=chatControl;
    // friendControl=new FriendController(accountControl->getPath(),accountControl->getAccountId(username));

    this->username=username;
    initialize();
    changeScreen(select(7));

}

MainMenu::~MainMenu()
{

}

void MainMenu::drawScreen(int v) {

    // clear screen return cursor to (0,0)
    clear();

    // print the instructions for manipulating the Value object
    mvprintw(0, 0, "Main Menu\nPlease select one by using the arrow keys and pressing enter:");
    mvprintw(3, 8, "Edit Pofile");
    mvprintw(4, 8, "Friends");
    mvprintw(5, 8, "Post");
    mvprintw(6, 8, "See feed");
    mvprintw(7, 8, "Groups");
    mvprintw(8, 8, "Chats");
    mvprintw(9, 8, "Logout");

    mvprintw(v+2, 5, "->");


    refresh();
}

void MainMenu::changeScreen(int selection){

    // cleanup the window and return control to bash
    endwin();

    if(selection==2)
        friends = new FriendsUI(username,accountControl);//new FriendController(accountControl->getPath(),accountControl->getAccountId(username)));

    /**
        else if(selection==3)

        else if(selection==4)

        else if(selection==5)

        **/
    else if(selection==6)
        chats = new ChatUI(username,accountControl);

    else if(selection==7)
        return;

    initialize();
    changeScreen(select(7));
}
