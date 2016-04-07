#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionSettings_triggered();

    void on_actionAccounts_triggered();

    void on_actionFriends_triggered();

    void on_actionNotifications_triggered();

    void on_actionFeed_triggered();

    void on_actionLog_out_triggered();

    void on_actionGroups_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
