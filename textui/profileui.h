#ifndef PROFILEUI_H
#define PROFILEUI_H

#include "screen.h"

class ProfileUI: public Screen
{
public:
    ProfileUI(AccountController* accountControl);
    void drawScreen(int v);
    void run();
    void displayInfo();

};

#endif // PROFILEUI_H
