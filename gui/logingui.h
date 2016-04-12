#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QWidget>
#include <string>
#include "../database/accountdb.h"

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QWidget
{
    Q_OBJECT

public:
    explicit LoginGUI(AccountDB *inputAccountDB, QWidget *parent = 0);
    ~LoginGUI();

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

private:
    Ui::LoginGUI *ui;
    AccountDB *accountDB;
};

#endif // LOGINGUI_H
