#ifndef GROUPSUI_H
#define GROUPSUI_H

#include "screen.h"

class GroupsUI:public Screen
{
public:
    GroupsUI(AccountController* accountControl);
    void run();
};

#endif // GROUPSUI_H
