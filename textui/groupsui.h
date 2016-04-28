#ifndef GROUPSUI_H
#define GROUPSUI_H

#include "screen.h"

typedef std::tuple<int, std::string> GroupIDNameType;

class GroupsUI:public Screen
{
public:
    GroupsUI(AccountController* accountControl);
    void run();
    int selectGroup();
    void enterGroup(int index);
private:
    std::vector<GroupIDNameType> groupIDNames;
};

#endif // GROUPSUI_H
