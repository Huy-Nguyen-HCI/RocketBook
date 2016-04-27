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
    explicit MainWindow(AccountController *inputAccountController, QWidget *parent = 0);
    void setUp();
    void setUsername(QString input) { username = input; }
    void setAccountController(AccountController *input) { accountController = input; }
    ~MainWindow();

private slots:
    void on_actionFeed_triggered();

    void on_actionAboutMe_triggered();

    void on_actionNotifications_triggered();

    void on_actionFriend_triggered();

    void on_actionLog_out_triggered();

    void on_actionGroups_triggered();

    void on_actionMessaging_triggered();

    void on_actionScrapbook_triggered();

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
