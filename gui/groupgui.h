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
    explicit GroupGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~GroupGUI();

    void switchGroupViews();

private:
    Ui::GroupGUI *ui;
    AccountController* accountController;
    DisplayGroupGUI* displayGroupView;
    CreateGroupGUI* createGroupView;
    ScrapbookGUI* currentGroupView;

};

#endif // GROUPGUI_H
