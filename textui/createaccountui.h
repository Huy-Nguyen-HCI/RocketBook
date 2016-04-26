#ifndef CREATEACCOUNTUI_H
#define CREATEACCOUNTUI_H

#include "screen.h"
#include "mainmenu.h"

class CreateAccountUI: public Screen
{
public:
    CreateAccountUI(AccountController* accountControl);
    void run();
    MainMenu* menu;
};

#endif // CREATEACCOUNTUI_H
