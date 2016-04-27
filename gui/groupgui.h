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

class GroupGUI : public QWidget
{
    Q_OBJECT

public:
    enum GroupGUIType {ShowAllGroups, CreateGroup, ViewGroupProfile, EnterScrapbook};

    explicit GroupGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~GroupGUI();

    void switchGroupViews(GroupGUIType type);
    void addGroupScrapbook(ScrapbookGUI *groupWidget);
    void addGroupProfile(GroupProfileGUI *profileView);

private slots:
    void on_returnButton_clicked();

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
