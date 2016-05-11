#ifndef CREATEACCOUNTUI_H
#define CREATEACCOUNTUI_H

#include "screen.h"
#include "mainmenu.h"

/**
 * @brief This screen allows user to create a new account
 */



class CreateAccountUI: public Screen
{
public:
    /**
     * @brief CreateAccountUI
     * Screen for creating accounts
     * @param accountControl Account Controller
     */
    CreateAccountUI(AccountController* accountControl);
    /**
     * @brief Run
     * Asks user for necessary information to create an account and opens main menu if account creation is successful
     */
    void run();
    MainMenu* menu;
};

#endif // CREATEACCOUNTUI_H
