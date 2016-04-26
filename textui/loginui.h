#ifndef LOGINTEXTUI_H
#define LOGINTEXTUI_H

#include "screen.h"
#include "mainmenu.h"

class LoginUI: public Screen{
public:
    LoginUI(AccountController* accountControl);
    void run();
    MainMenu* menu;

};

#endif // LOGINTEXTUI_H
