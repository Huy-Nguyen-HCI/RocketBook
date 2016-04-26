#ifndef CHATUI_H
#define CHATUI_H


#include "screen.h"

#include "../model/chatcontroller.h"
#include "../model/accountcontroller.h"


class ChatUI: public Screen{
public:
    ChatUI(AccountController* accountControl);
    int run();

    QString username;
    void drawScreen(int v);
    void displayChats(int v);
    void takeCommand(int selection);

private:
    AccountController* accountControl;
    ChatController* chatControl;
    void createChat();
    void selectChat();
    int chatSelection();
    void enterChat(int chatId);
    std::vector<int>* chatList;

};

#endif // CHATUI_H
