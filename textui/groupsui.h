#ifndef GROUPSUI_H
#define GROUPSUI_H

#include "screen.h"

class GroupsUI:public Screen
{
public:
    GroupsUI(AccountController* accountControl);
    void run();
    int selectGroup();
    void enterGroup(int index);
};

#endif // GROUPSUI_H
