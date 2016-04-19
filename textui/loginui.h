#ifndef LOGINTEXTUI_H
#define LOGINTEXTUI_H

#include "ncurses.h"
#include "screen.h"

#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"



class LoginUI: public Screen{
public:
    LoginUI();
    void run();


private:
    AccountController *accountController;
};

#endif // LOGINTEXTUI_H
