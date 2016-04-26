#ifndef PROFILEUI_H
#define PROFILEUI_H

#include "screen.h"

class ProfileUI: public Screen
{
public:
    ProfileUI(AccountController* accountControl);
    void run();

};

#endif // PROFILEUI_H
