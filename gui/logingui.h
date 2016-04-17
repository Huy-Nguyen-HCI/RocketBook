#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QWidget>
#include <string>
#include "../model/accountcontroller.h"
#include "mainwindow.h"
#include "createaccountgui.h"

class MainWindow;
class CreateAccountGUI;

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QWidget
{
    Q_OBJECT

public:
    explicit LoginGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~LoginGUI();
    void setMainWindow(MainWindow *input) { main = input; }
    void setCreateAccountView(CreateAccountGUI *input) { createAccountView = input; }
    void clearAllFields();

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

private:
    Ui::LoginGUI *ui;
    AccountController *accountController;
    MainWindow *main;
    CreateAccountGUI *createAccountView;
};

#endif // LOGINGUI_H
