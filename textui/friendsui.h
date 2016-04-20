#ifndef FRIENDSUI_H
#define FRIENDSUI_H

#include "screen.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/accountcontroller.h"


class FriendsUI: public Screen{
public:
    FriendsUI(QString username, AccountController* accountControl);

    void run();

    QString username;

private:
    AccountController* accountControl;

};

#endif // FRIENDSUI_H
