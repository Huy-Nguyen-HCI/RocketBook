#ifndef CHATUI_H
#define CHATUI_H


#include "screen.h"

#include "../model/accountcontroller.h"

/**
 * @brief The chatUI screen includes all chat functionality for textUI
 */


class ChatUI: public Screen{
public:
    /**
     * @brief ChatUI constructor
     * @param accountController Account Controller
     *
     */

    ChatUI(AccountController* accountControl);
    /**
     * @brief Run
     * initiates action
     *
     */
    int run();

    QString username;
    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    void drawScreen(int v);
    /**
     * @brief Take command
     * Makes new screen based on user selection
     * @param selection Pointer value when enter is pressed
     */
    void takeCommand(int selection);

private:
    AccountController* accountControl;
    ChatController* chatControl;
    FriendController* friendControl;
    /**
     * @brief create Chat with friend
     * @param id Friend id
     */
    void createChat(int id);
    /**
     * @brief displays chat room on screen
     */
    void enterChat();
    /**
     * @brief Displays chat rooms and allows user to select chat
     */
    int chatSelection();
    /**
     * @brief chat Room
     * Includes functionality for chating. Displays chats and allows user to send messages
     * @param index of chat room
     */
    void chatRoom(int index);
    /**
     * @brief addFriend
     * Adds friend to chat
     * @param chatIndex index of chat in chat list
     * @param friendIndex Index of friend on friends list
     */
    void addFriend(int chatIndex, int friendIndex);
    /**
     * @brief leaveChat
     * Removes current user from chat
     * @param chatIndex index of chat in chat list
     */
    void leaveChat(int index);
    /**
     * @brief SendMessage
     * User sends message in chat
     * @param chatId Id of chat
     */
    void sendMessage(int chatId);

    /**
     * @brief Prompts user to select Friend
     * @return Index of selected friend on friend list
     */
    int selectFriend();
    /**
     * @brief Prompts user to select Chat
     * @return Index of selected chat on chat list
     */
    int selectChat();
    /**
     * @brief scrollMessages
     * Scrolls through messages
     * @return current position of pointer on screen
     */
    int scrollMessages();

};

#endif // CHATUI_H
