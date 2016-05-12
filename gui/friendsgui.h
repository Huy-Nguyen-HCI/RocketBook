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
    /**
     * @brief FriendsGUI the class contructor.
     * @param input pointer to the account controller that contains information about the user.
     * @param parent the parent QWidget class.
     */
    explicit FriendsGUI(AccountController *input, QWidget *parent = 0);

    /**
      * @brief ~FriendsGUI the class destructor. Delete the pointer to ui.
      */
    ~FriendsGUI();

    /**
     * @brief refreshFriendList load and display all the friends.
     */
    void refreshFriendList();

private slots:
    /**
     * @brief on_viewProfile_clicked create a new view that displays the selected friend's profile.
     */
    void on_viewProfile_clicked();

    /**
     * @brief on_removeFriend_clicked remove the selected friend from the friend list.
     */
    void on_removeFriend_clicked();

    /**
     * @brief on_addFriend_clicked add the friend with the input username to the friend list.
     */
    void on_addFriend_clicked();

private:
    Ui::FriendsGUI *ui;
    AccountController *accountController;
    QCompleter *completer;
};

#endif // FRIENDSGUI_H
