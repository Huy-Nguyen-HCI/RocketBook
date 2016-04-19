#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include "loginui.h"
#include <string>

class MainMenu: public Screen
{
public:
    MainMenu();
    ~MainMenu();

    //Screens
    LoginUI* login;




    int run();
    void DrawScreen(int v);
    void changeScreen(int selection);
};

#endif // MAINMENU_H
