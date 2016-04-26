#include "mainmenu.h"

MainMenu::MainMenu(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    options=8;
    changeScreen(select(options));

}

MainMenu::~MainMenu()
{

}

void MainMenu::drawScreen(int v) {

    clear();

    mvprintw(0, 0, "Dashboard");
    mvprintw(3, 8, "About Me");
    mvprintw(4, 8, "Feed");
    mvprintw(5, 8, "Notifications");
    mvprintw(6, 8, "Friends");
    mvprintw(7, 8, "Scrapbook");
    mvprintw(8, 8, "Messaging");
    mvprintw(9, 8, "Groups");
    mvprintw(10, 8, "Logout");

    mvprintw(v+2, 5, "->");
    refresh();
}

void MainMenu::changeScreen(int selection){

    endwin();

    if(selection==1)
        profile = new ProfileUI(accountControl);

    else if(selection==2)
        feed = new FeedUI(accountControl);

    else if(selection==3);


    else if(selection==4)
        friends = new FriendsUI(accountControl);

    else if(selection==5)
        scrapbook = new ScrapbookUI(accountControl);

    else if(selection==6)
        chats = new ChatUI(accountControl);

    else if(selection==7)
        groups = new GroupsUI(accountControl);

    else if(selection==8)
        return;

    initialize();
    changeScreen(select(options));
}
