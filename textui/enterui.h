#ifndef ENTERUI_H
#define ENTERUI_H

#include "screen.h"
#include "loginui.h"
#include "createaccountui.h"

class EnterUI: public Screen
{
public:
    EnterUI(AccountController* accountControl);

    void drawScreen(int v);
    void changeScreen(int selection);

    //Screens
    LoginUI* login;
    CreateAccountUI* create;

};

#endif // ENTERUI_H
