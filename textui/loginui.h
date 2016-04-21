#ifndef LOGINTEXTUI_H
#define LOGINTEXTUI_H

#include "ncurses.h"
#include "screen.h"
#include "mainmenu.h"

#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"
#include "../model/chatcontroller.h"
#include "../model/rocketuser.h"


class LoginUI: public Screen{
public:
    LoginUI(AccountController* accountControl);
    void run();
    MainMenu* menu;

private:
    AccountController *accountControl;
};

#endif // LOGINTEXTUI_H
