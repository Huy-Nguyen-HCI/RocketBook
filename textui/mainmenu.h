#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include <string>
#include "friendsui.h"
#include "scrapbookui.h"
#include "chatui.h"
#include "profileui.h"

class MainMenu: public Screen
{
public:
    MainMenu(AccountController* accountControl);
    ~MainMenu();

    //Screens
    FriendsUI* friends;
    ChatUI* chats;
    ScrapbookUI* scrapbook;
    ProfileUI* profile;



    void drawScreen(int v);
    void changeScreen(int selection);

};

#endif // MAINMENU_H
