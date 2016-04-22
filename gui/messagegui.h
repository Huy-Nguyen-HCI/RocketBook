#ifndef MESSAGEGUI_H
#define MESSAGEGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"

namespace Ui {
class MessageGUI;
}

class MessageGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MessageGUI(AccountController *input, QWidget *parent = 0);
    ~MessageGUI();
    void refreshChats();
    void refreshFriendList();

private:
    Ui::MessageGUI *ui;
    AccountController *accountController;
};

#endif // MESSAGEGUI_H
