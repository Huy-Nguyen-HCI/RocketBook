#ifndef GROUPGUI_H
#define GROUPGUI_H

#include <QWidget>
#include "displaygroupgui.h"
#include "creategroupgui.h"
#include "scrapbookgui.h"

class DisplayGroupGUI;
class CreateGroupGUI;

namespace Ui {
class GroupGUI;
}

class GroupGUI : public QWidget
{
    Q_OBJECT

public:
    enum GroupGUIType {ShowAllGroups, CreateGroup, EditGroup, ViewGroup};

    explicit GroupGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~GroupGUI();

    void switchGroupViews(GroupGUIType type);
    void addWidget(ScrapbookGUI *groupWidget);
    void showReturnButton();


private slots:
    void on_returnButton_clicked();

private:
    Ui::GroupGUI *ui;
    AccountController* accountController;
    DisplayGroupGUI* displayGroupView;
    CreateGroupGUI* createGroupView;
    ScrapbookGUI* currentGroupView;

};

#endif // GROUPGUI_H
