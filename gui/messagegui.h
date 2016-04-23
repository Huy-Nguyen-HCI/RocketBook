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

private slots:
    void on_addToChat_clicked();

    void on_createChat_clicked();

    void on_leaveChat_clicked();

    void on_enterChat_clicked();

private:
    Ui::MessageGUI *ui;
    AccountController *accountController;
};

#endif // MESSAGEGUI_H
