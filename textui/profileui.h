#ifndef PROFILEUI_H
#define PROFILEUI_H

#include "screen.h"

class ProfileUI: public Screen
{
public:
    ProfileUI(AccountController* accountControl);
    void drawScreen(int v);
    void displayInfo();
    void takeCommand(int selection);
    void viewProfile();
    void editDescription();

};

#endif // PROFILEUI_H
