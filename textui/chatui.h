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
    void chatRoom(int index);
    void addFriend(int chatIndex, int friendIndex);
    void leaveChat(int index);
    void sendMessage(int chatId);

    int selectFriend();
    int selectChat();
    int scrollMessages();

};

#endif // CHATUI_H
