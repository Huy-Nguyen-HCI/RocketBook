#ifndef CREATEGROUPGUI_H
#define CREATEGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "groupgui.h"

class GroupGUI;

namespace Ui {
class CreateGroupGUI;
}

class CreateGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroupGUI(AccountController *inputAccountController, GroupGUI* groupGUI, QWidget *parent = 0);
    ~CreateGroupGUI();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

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
