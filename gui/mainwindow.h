#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QString>
#include "logingui.h"
#include "createbloggui.h"
#include "createmultimediagui.h"
#include "createtweetgui.h"
#include "dashboardgui.h"
#include "scrapbookgui.h"
#include "profilegui.h"
#include "friendsgui.h"
#include "messagegui.h"
#include "groupgui.h"
#include "aboutgui.h"

class LoginGUI;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow Main window constructor that creates toolbar
     * @param inputAccountController the input model
     * @param parent
     */
    explicit MainWindow(AccountController *inputAccountController, QWidget *parent = 0);

    /**
     * @brief setUp
     * Set up the main window
     */
    void setUp();

    /**
     * @brief setUsername
     * Set the user name of the window
     * @param input The username of the window
     */
    void setUsername(QString input) { username = input; }

    /**
     * @brief setAccountController
     * Set the model for the main window
     * @param input The input model
     */
    void setAccountController(AccountController *input) { accountController = input; }
    ~MainWindow();

private slots:

    /**
     * @brief on_actionFeed_triggered
     * Open feed widget
     */
    void on_actionFeed_triggered();

    /**
     * @brief on_actionAboutMe_triggered
     * Open profile widget
     */
    void on_actionAboutMe_triggered();

    /**
     * @brief on_actionFriend_triggered
     * Open friends widget
     */
    void on_actionFriend_triggered();

    /**
     * @brief on_actionLog_out_triggered
     * Log out of the window
     */
    void on_actionLog_out_triggered();

    /**
     * @brief on_actionGroups_triggered
     * Go to Groups
     */
    void on_actionGroups_triggered();

    /**
     * @brief on_actionMessaging_triggered
     * Go to Messaging
     */
    void on_actionMessaging_triggered();

    /**
     * @brief on_actionScrapbook_triggered
     * Go to Scrapbook
     */
    void on_actionScrapbook_triggered();

    /**
     * @brief on_actionAbout_Rocketbook_triggered
     * Go to About Rocketbook section
     */
    void on_actionAbout_Rocketbook_triggered();

private:
    Ui::MainWindow *ui;
    QString username;
    DashboardGUI *dashboard;
    ScrapbookGUI *scrapbook;
    ProfileGUI *profile;
    AccountController *accountController;
    LoginGUI *login;
    FriendsGUI *friends;
    MessageGUI *messages;
    GroupGUI* groups;
    AboutGUI *about;

};

#endif // MAINWINDOW_H
