#ifndef LOGINTEXTUI_H
#define LOGINTEXTUI_H

#include "screen.h"
#include "mainmenu.h"

/**
 * @brief Login Screen. Asks user for username and password. Creates main menu of password is
 * correct for entered username
 */
class LoginUI: public Screen{
public:
    /**
     * @brief LoginUI
     * @param accountController Account Controller
     */
    LoginUI(AccountController* accountControl);
    /**
     * @brief run
     * Asks user for username and password. Creates main menu of password is
     * correct for entered username
     */
    void run();
    MainMenu* menu;

};

#endif // LOGINTEXTUI_H
