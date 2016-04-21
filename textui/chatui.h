#ifndef CHATUI_H
#define CHATUI_H


#include "screen.h"
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);//       <----- Don't as why this is here
#include "../model/chatcontroller.h"
#include "../model/accountcontroller.h"


class ChatUI: public Screen{
public:
    ChatUI(QString username, AccountController* accountControl);
    int run();

    QString username;
    void DrawScreen(int v);
    void takeCommand(int selection);

private:
    AccountController* accountControl;
    ChatController* chatControl;
};

#endif // CHATUI_H
