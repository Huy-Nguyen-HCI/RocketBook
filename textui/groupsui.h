#ifndef GROUPSUI_H
#define GROUPSUI_H

#include "screen.h"
#include "groupscrapbookui.h"

typedef std::tuple<int, std::string> GroupIDNameType;
void viewBlog(int index);
/**
 * @brief The GroupsUI handles functionality for creating groups and editing group profiles
 * in text UI. Users can also create a new GroupScrapbookUI from this screen.
 */

class GroupsUI:public Screen
{
public:
    /**
     * @brief GroupsUI
     * @param accountControl Account Controller
     */
    GroupsUI(AccountController* accountControl);
    /**
     * @brief Select Group
     * Displays list of groups and allows user to select one to enter
     */
    int selectGroup();
    /**
     * @brief Enter Group
     * Enters selected group
     * @param index Index of selected group on group list
     */
    void enterGroup(int index);
    /**
     * @brief View Profile
     * Views profile of selected group
     * @param index Index of selected group on group list
     */
    void viewProfile(int index);
    /**
     * @brief Take command
     * Makes new screen based on user selection
     * @param selection Pointer value when enter is pressed
     */
    void takeCommand(int selection);
    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    void drawScreen(int v);
    /**
     * @brief Create Group
     * Asks user to enter necessary information to create a group and creates group with
     * indicated information
     */
    void createGroup();

    GroupScrapbookUI* scrapbook;
private:
    std::vector<GroupIDNameType> groupIDNames;


};

#endif // GROUPSUI_H
