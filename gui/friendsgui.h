#ifndef FRIENDSGUI_H
#define FRIENDSGUI_H

#include <QWidget>
#include <QCompleter>
#include "../model/accountcontroller.h"
#include "friendprofilegui.h"

namespace Ui {
class FriendsGUI;
}

class FriendsGUI : public QWidget
{
    Q_OBJECT

public:
    explicit FriendsGUI(AccountController *input, QWidget *parent = 0);
    ~FriendsGUI();
    void refreshFriendList();

private slots:
    void on_viewProfile_clicked();

    void on_removeFriend_clicked();

    void on_addFriend_clicked();

private:
    Ui::FriendsGUI *ui;
    AccountController *accountController;
    QCompleter *completer;
};

#endif // FRIENDSGUI_H
