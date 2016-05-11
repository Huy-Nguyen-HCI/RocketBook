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
 * Provides functionality for the chat interface
 */
class ChatGUI : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief ChatGUI
     * @param input The input model
     * @param chatId Chat ID
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
    void on_send_clicked();
    void refreshMembers();
    void refreshMessages();
    void on_chatBox_returnPressed();
};

#endif // CHATGUI_H
