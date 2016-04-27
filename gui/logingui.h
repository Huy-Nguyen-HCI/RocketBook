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
    static bool isFinished() { return finished; }

private slots:
    bool on_loginButton_clicked();

    void on_createAccountButton_clicked();

    void on_quitButton_clicked();

private:
    Ui::LoginGUI *ui;
    AccountController *accountController;
    MainWindow *main;
    CreateAccountGUI *createAccountView;
    static bool finished;

    void closeEvent(QCloseEvent *event);
};

#endif // LOGINGUI_H
