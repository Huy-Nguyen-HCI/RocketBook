#ifndef CHATUI_H
#define CHATUI_H


#include "screen.h"

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
    FriendController* friendControl;
    void createChat(int id);
    void enterChat();
    int chatSelection();
    void enterChat(int chatId);
    void addFriend();
    void leaveChat();
    std::vector<int>* chatList;
    int selectFriend();

};

#endif // CHATUI_H
