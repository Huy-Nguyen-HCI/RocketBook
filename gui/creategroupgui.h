#ifndef CREATEGROUPGUI_H
#define CREATEGROUPGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"

namespace Ui {
class CreateGroupGUI;
}

class CreateGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroupGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~CreateGroupGUI();

private:
    Ui::CreateGroupGUI *ui;
    AccountController* accountController;
};

#endif // CREATEGROUPGUI_H
