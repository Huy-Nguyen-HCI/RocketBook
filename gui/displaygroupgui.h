#ifndef DISPLAYGROUPGUI_H
#define DISPLAYGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "groupgui.h"

class GroupGUI;

namespace Ui {
class DisplayGroupGUI;
}

/**
 * @brief The DisplayGroupGUI class displays all the groups the user belongs to.
 */
class DisplayGroupGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief DisplayGroupGUI the class constructor.
     * @param inputAccountController the account controller that contains information about the user.
     * @param groupGUI the corresponding group UI.
     * @param parent the QWidget parent.
     */
    explicit DisplayGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent = 0);

    /**
      * @brief ~DisplayGroupGUI the class destructor. Delete the pointer to ui.
      */
    ~DisplayGroupGUI();

    /**
     * @brief refreshGroups refresh the group view.
     */
    void refreshGroups();

private:
    Ui::DisplayGroupGUI *ui;
    AccountController* accountController;
    GroupGUI* groupGUI;


private slots:
    /**
     * @brief cell_clicked show the Enter group button when a group is selected.
     */
    void cell_clicked();

    /**
     * @brief on_enterGroupButton_clicked segue to the group profile view.
     */
    void on_enterGroupButton_clicked();

    /**
     * @brief on_createGroupButton_clicked segue to the create group view.
     */
    void on_createGroupButton_clicked();
};

#endif // DISPLAYGROUPGUI_H
