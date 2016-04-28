#include "mainmenu.h"

MainMenu::MainMenu(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    options=7;
    changeScreen(select(options));

}

MainMenu::~MainMenu()
{

}

void MainMenu::drawScreen(int v) {

    clear();

    mvprintw(0, 0, "Dashboard");
    mvprintw(3, 8, "Profile");
    mvprintw(4, 8, "Feed");
    mvprintw(5, 8, "Friends");
    mvprintw(6, 8, "Scrapbook");
    mvprintw(7, 8, "Messaging");
    mvprintw(8, 8, "Groups");
    mvprintw(9, 8, "Logout");

    mvprintw(v+2, 5, "->");
    refresh();
}

void MainMenu::changeScreen(int selection){

    endwin();

    if(selection==1)
        profile = new ProfileUI(accountControl);

    else if(selection==2)
        feed = new FeedUI(accountControl);


    else if(selection==3)
        friends = new FriendsUI(accountControl);

    else if(selection==4)
        scrapbook = new ScrapbookUI(accountControl);

    else if(selection==5)
        chats = new ChatUI(accountControl);

    else if(selection==6)
        groups = new GroupsUI(accountControl);

    else if(selection==7)
        return;

    initialize();
    changeScreen(select(options));
}
