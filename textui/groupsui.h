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
    void viewProfile(int index);
    void takeCommand(int selection);
    void drawScreen(int v);
    void createGroup();
private:
    std::vector<GroupIDNameType> groupIDNames;


};

#endif // GROUPSUI_H
