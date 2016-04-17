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

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void setUsername(QString input) { username = input; }
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
};

#endif // MAINWINDOW_H
