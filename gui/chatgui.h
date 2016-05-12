#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include "../model/accountcontroller.h"
#include <QCloseEvent>

namespace Ui {
class ChatGUI;
}

/**
 * @brief The ChatGUI class
 * Provides functionality for the chat interface. The chat has an instant refresh rate of .5 second
 */
class ChatGUI : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief ChatGUI
     * @param input The current account of the user
     * @param chatId The ID of the chatroom
     * @param parent
     *
     * Default constructor
     */
    explicit ChatGUI(AccountController *input, int chatId, QWidget *parent = 0);

    ~ChatGUI();

private:
    Ui::ChatGUI *ui;
    QGraphicsScene *scene;

    AccountController *accountController;
    int chatId;
    void closeEvent(QCloseEvent *event);


    QTimer *timer;


private slots:
    /**
     * @brief on_send_clicked
     * Send a message to the other person
     */
    void on_send_clicked();

    /**
     * @brief refreshMembers
     * Refresh all members currently in the chat
     */
    void refreshMembers();

    /**
     * @brief refreshMessages
     * Refresh all messages currently in the chat.
     * This slot connects to the timer, and the refresh rate is 0.5 second.
     */
    void refreshMessages();

    /**
     * @brief on_chatBox_returnPressed
     * Send a message to the other person.
     */
    void on_chatBox_returnPressed();
};

#endif // CHATGUI_H
