#ifndef PROFILEUI_H
#define PROFILEUI_H

#include "screen.h"

/**
 * @brief The profile class handles profile functionality in Text UI. This includes
 * editing and viewing profile.
 */

class ProfileUI: public Screen
{
public:
    /**
     * @brief ProfileUI
     * @param accountController Account Controller
     */
    ProfileUI(AccountController* accountControl);
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
    /**
     * @brief Displays profile Info on screen
     */
    void viewProfile();
    /**
     * @brief Allows user to enter new profile description
     */
    void editDescription();

};

#endif // PROFILEUI_H
