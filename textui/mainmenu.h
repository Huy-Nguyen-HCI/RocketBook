#ifndef MAINMENU_H
#define MAINMENU_H
#include "screen.h"
#include <string>
#include "friendsui.h"
#include "scrapbookui.h"
#include "chatui.h"
#include "profileui.h"
#include "feedui.h"
#include "groupsui.h"
/**
 * @brief The Main Menu Prompts the to select one of several different actions. These
 * actions include profile, feed, scrapbook, friends, groups, messaging, and logout.
 */
class MainMenu: public Screen
{
public:
    /**
     * @brief MainMenu
     * Displays Main Menu
     * @param accountController Account Controller
     */
    MainMenu(AccountController* accountControl);
    /**
     * @brief ~MainMenu
     */
    ~MainMenu();

    //Screens
    FriendsUI* friends;
    ChatUI* chats;
    ScrapbookUI* scrapbook;
    ProfileUI* profile;
    FeedUI* feed;
    GroupsUI* groups;


    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    void drawScreen(int v);
    /**
     * @brief Change Screen
     * Makes new screen based on user selection
     * @param selection Pointer (arrow on screen) value when enter is pressed
     */
    void changeScreen(int selection);

};

#endif // MAINMENU_H
