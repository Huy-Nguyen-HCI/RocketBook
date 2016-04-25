#ifndef DISPLAYGROUPGUI_H
#define DISPLAYGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "groupgui.h"

class GroupGUI;

namespace Ui {
class DisplayGroupGUI;
}

class DisplayGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent = 0);
    ~DisplayGroupGUI();

private:
    Ui::DisplayGroupGUI *ui;
    AccountController* accountController;
    GroupGUI* groupGUI;
    void refreshGroups();


private slots:
    void on_cell_clicked( int row, int column );
    void on_enterGroupButton_clicked();
    void on_createGroupButton_clicked();
};

#endif // DISPLAYGROUPGUI_H
