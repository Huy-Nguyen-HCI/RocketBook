#ifndef FRIENDSUI_H
#define FRIENDSUI_H

#include "screen.h"

#include "../model/accountcontroller.h"
#include "../model/rocketuser.h"

/**
 * @brief The friends UI controls all friend actions in Text UI. This includes viewing friends
 *         list, viewing friends profile, adding friends, and removing friends.
 */

class FriendsUI: public Screen{
public:
    /**
     * @brief FriendsUI
     * @param accountController Account Controller
     */
    FriendsUI(AccountController* accountControl);// FriendController* friendControl);
    QString username;
    /**
     * @brief Draw screen
     * Asks user to add, deleted, r view friends
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
    FriendController* friendControl;
    RocketUser* user;
    /**
     * @brief add friend
     * Asks user to type in name and attempts to add this account to friends list
     */
    void addFriend();
    /**
     * @brief remove friend
     * Asks user to select friend to be removed from friends list
     */
    void removeFriend(int index);
    /**
     * @brief select friend
     *        Displays friends list and allows user to select a friend
     */
    int selectFriend();
    /**
     * @brief View friends profile
     * Views indicated friend's profile
     * @param v Index of selected friend on friends list
     *
     */
    int viewFriendsProfile(int v);

};

#endif // FRIENDSUI_H
