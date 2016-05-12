#ifndef CREATEGROUPGUI_H
#define CREATEGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "groupgui.h"

class GroupGUI;

namespace Ui {
class CreateGroupGUI;
}

/**
 * @brief The CreateGroupGUI class is a controller interface to create new groups
 */
class CreateGroupGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CreateGroupGUI default constructor
     * @param inputAccountController The account that is creating this new group
     * @param groupGUI The current groupGUI
     * @param parent
     */
    explicit CreateGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent = 0);
    ~CreateGroupGUI();

private slots:

    /**
     * @brief on_buttonBox_accepted
     * Create the group using information input
     */
    void on_buttonBox_accepted();

    /**
     * @brief on_buttonBox_rejected
     * Return to the previous window
     */
    void on_buttonBox_rejected();

    /**
     * @brief on_uploadPhotoButton_clicked
     * Open a pop up for user to select their photo
     */
    void on_uploadPhotoButton_clicked();

private:
    Ui::CreateGroupGUI *ui;
    AccountController* accountController;
    GroupGUI* groupGUI;
    QString photoPath;
    void clearAllFields();
    void updateFriendList();
};

#endif // CREATEGROUPGUI_H
