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

/**
 *      1. Create a ProfileGUI
 *      2. Populate the data in ProfileGUI from ProfileDB (might need a ProfileController class similar to AccountController for this)
 *      3. Create an instance of ProfileGUI in MainWindow (like line 54-57 of MainWindow.h)
 *      4. Put ProfileGUI to the top of the stack as About Me gets called.
 */

class LoginGUI;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(AccountController *inputAccountController, QWidget *parent = 0);
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

private:
    Ui::MainWindow *ui;
    QString username;
    DashboardGUI *dashboard;
    ScrapbookGUI *scrapbook;
    ProfileGUI *profile;
    AccountController *accountController;
    LoginGUI *login;
};

#endif // MAINWINDOW_H
