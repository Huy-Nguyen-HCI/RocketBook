#ifndef CREATEACCOUNTGUI_H
#define CREATEACCOUNTGUI_H

#include <QWidget>
#include "logingui.h"
#include "mainwindow.h"
#include <QGraphicsScene>

class LoginGUI;
class MainWindow;

namespace Ui {
class CreateAccountGUI;
}

/**
 * @brief The CreateAccountGUI class facilitates the creation of an account in the GUI
 */
class CreateAccountGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief CreateAccountGUI is the default constructor
     * @param input
     * @param parent
     */
    explicit CreateAccountGUI(AccountController *input, QWidget *parent = 0);

    /**
     * @brief setLoginView
     * Set which login view to be connected
     * @param input The LoginGUI class to be connected
     */
    void setLoginView(LoginGUI *input) { loginView = input; }

    ~CreateAccountGUI();

    /**
     * @brief clearAllFields Clear all the fields of the window
     */
    void clearAllFields();

    /**
     * @brief setMainWindow
     * Set the mainwindow input
     * @param input The mainwindow to be set as input
     */
    void setMainWindow(MainWindow *input) { main = input; }

private slots:

    /**
     * @brief on_uploadButton_clicked
     * Upload the photo of account as profile picture
     */
    void on_uploadButton_clicked();

    /**
     * @brief on_returnButton_clicked
     * Return to previous window
     */
    void on_returnButton_clicked();

    /**
     * @brief on_createButton_clicked
     * Retrieves all input information and creating a new account.
     * The next window to appear is the dashboard.
     */
    void on_createButton_clicked();


private:
    Ui::CreateAccountGUI *ui;
    LoginGUI *loginView;
    AccountController *accountController;
    MainWindow *main;
    QGraphicsScene *scene;
    QString photoPath;

};

#endif // CREATEACCOUNTGUI_H
