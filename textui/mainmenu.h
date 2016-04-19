#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"

class MainMenu: public Screen
{
public:
    MainMenu();
    ~MainMenu();
    int run();
    void DrawScreen(int v);
    void changeScreen(int selection);
};

#endif // MAINMENU_H
