#ifndef GROUPGUI_H
#define GROUPGUI_H

#include <QWidget>
#include "displaygroupgui.h"
#include "creategroupgui.h"
#include "scrapbookgui.h"
#include "groupprofilegui.h"

class DisplayGroupGUI;
class CreateGroupGUI;
class GroupProfileGUI;

namespace Ui {
class GroupGUI;
}

/**
 * @brief The GroupGUI class
 * The GUI that shows all the control interface for the group
 */
class GroupGUI : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief The GroupGUIType enum The different type of group GUI that could be switched between
     */
    enum GroupGUIType {ShowAllGroups, CreateGroup, ViewGroupProfile, EnterScrapbook};

    /**
     * @brief GroupGUI constructs the main group control
     * @param inputAccountController The model
     * @param parent
     */
    explicit GroupGUI(AccountController *inputAccountController, QWidget *parent = 0);

    ~GroupGUI();

    /**
     * @brief switchGroupViews
     * Switch between all the group views: show all groups, create group, view profile, enter scrapbook
     * @param type The type of Group GUI to switch to
     */
    void switchGroupViews(GroupGUIType type);

    /**
     * @brief addGroupScrapbook
     * Add a scrapbook GUI as a group scrapbook
     * @param groupWidget the scrapbook GUI for the group
     */
    void addGroupScrapbook(ScrapbookGUI *groupWidget);

    /**
     * @brief addGroupProfile
     * Add a profile GUI for the group
     * @param profileView the profile view for the group
     */
    void addGroupProfile(GroupProfileGUI *profileView);

private slots:
    /**
     * @brief on_returnButton_clicked
     * Return to the main all group display
     */
    void on_returnButton_clicked();

    /**
     * @brief on_groupSwitchButton_clicked
     * Switch to another view, depending on the current view
     */
    void on_groupSwitchButton_clicked();

private:
    Ui::GroupGUI *ui;
    AccountController* accountController;
    DisplayGroupGUI* displayGroupView;
    CreateGroupGUI* createGroupView;
    ScrapbookGUI* currentGroupView;
    GroupProfileGUI* groupProfileView;

};

#endif // GROUPGUI_H
