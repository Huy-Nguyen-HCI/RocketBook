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

/**
 * @brief The LoginGUI class provides the functionality to login to the application
 */
class LoginGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief LoginGUI constructs a login window
     * @param inputAccountController The model
     * @param parent
     */
    explicit LoginGUI(AccountController *inputAccountController, QWidget *parent = 0);

    ~LoginGUI();

    /**
     * @brief setMainWindow sets the main window in the class
     * @param input the main window
     */
    void setMainWindow(MainWindow *input) { main = input; }

    /**
     * @brief setCreateAccountView sets the create account window
     * @param input the Create Account window
     */
    void setCreateAccountView(CreateAccountGUI *input) { createAccountView = input; }

    /**
     * @brief clearAllFields
     * Clears all fields in the Login UI
     */
    void clearAllFields();

    /**
     * @brief isFinished When the LoginUI can be closed
     * @return
     */
    static bool isFinished() { return finished; }

    /**
     * @brief login Login to the account
     */
    bool login();

private slots:
    /**
     * @brief on_loginButton_clicked Log in when the button is clicked
     * @return true if successful, false if not
     */
    bool on_loginButton_clicked();

    /**
     * @brief on_createAccountButton_clicked Open create account
     */
    void on_createAccountButton_clicked();

    /**
     * @brief on_quitButton_clicked Quit the UI
     */
    void on_quitButton_clicked();

    /**
     * @brief on_passwordBox_returnPressed
     * Alternative way to log in
     * @return true if successful, false if fails
     */
    bool on_passwordBox_returnPressed();

private:
    Ui::LoginGUI *ui;
    AccountController *accountController;
    MainWindow *main;
    CreateAccountGUI *createAccountView;
    static bool finished;

    void closeEvent(QCloseEvent *event);
};

#endif // LOGINGUI_H
