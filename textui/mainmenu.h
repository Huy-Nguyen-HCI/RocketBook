#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include <string>
#include "friendsui.h"

class MainMenu: public Screen
{
public:
    MainMenu(QString username);
    ~MainMenu();

    //Screens
    FriendsUI* friends;



    QString username;







    int run();
    void DrawScreen(int v);
    void changeScreen(int selection);
};

#endif // MAINMENU_H
