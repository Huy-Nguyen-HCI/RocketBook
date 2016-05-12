#ifndef MESSAGEGUI_H
#define MESSAGEGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "chatgui.h"

namespace Ui {
class MessageGUI;
}

/**
 * @brief The MessageGUI class provides the user interface for all chatrooms
 */
class MessageGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief MessageGUI is the default constructor
     * @param input the account that handles message
     * @param parent
     */
    explicit MessageGUI(AccountController *input, QWidget *parent = 0);
    ~MessageGUI();

    /**
     * @brief refreshChats refresh the chat list
     */
    void refreshChats();

    /**
     * @brief refreshFriendList refreshes the friend's list
     */
    void refreshFriendList();

private slots:
    /**
     * @brief on_addToChat_clicked
     * Add the friend to a chatroom
     */
    void on_addToChat_clicked();

    /**
     * @brief on_createChat_clicked
     * Create a new chatroom with the friends selected
     */
    void on_createChat_clicked();

    /**
     * @brief on_leaveChat_clicked
     * Leave a chat room
     */
    void on_leaveChat_clicked();

    /**
     * @brief on_enterChat_clicked
     * Open the chat room
     */
    void on_enterChat_clicked();

private:
    Ui::MessageGUI *ui;
    AccountController *accountController;
};

#endif // MESSAGEGUI_H
