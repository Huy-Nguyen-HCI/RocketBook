#ifndef ENTERUI_H
#define ENTERUI_H

#include "screen.h"
#include "loginui.h"
#include "createaccountui.h"

/**
 * @brief The EnterUI is the first screen in the TextUI. Allows user to log in or create
 *        a new account.
 */


class EnterUI: public Screen
{
public:
    /**
     * @brief EnterUI
     * First screen to enter program
     * @param accountControl Account Controller
     */
    EnterUI(AccountController* accountControl);
    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    void drawScreen(int v);
    /**
     * @brief Change Screen
     * Makes new screen based on user selection
     * @param selection Pointer value when enter is pressed
     */
    void changeScreen(int selection);

    //Screens
    LoginUI* login;
    CreateAccountUI* create;

};

#endif // ENTERUI_H
