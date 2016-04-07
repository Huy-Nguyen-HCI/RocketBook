#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::on_actionSettings_triggered segues to the Settings view.
 *
 * Triggered when Settings button is clicked.
 */
void MainWindow::on_actionSettings_triggered()
{

}

/**
 * @brief MainWindow::on_actionAccounts_triggered segues to the Accounts view.
 *
 * Triggered when Accounts button is clicked.
 */
void MainWindow::on_actionAccounts_triggered()
{

}

/**
 * @brief MainWindow::on_actionFriends_triggered segues to the Friends view.
 *
 * Triggered when Friends button is clicked.
 */
void MainWindow::on_actionFriends_triggered()
{

}

/**
 * @brief MainWindow::on_actionNotifications_triggered segues to the Notification view.
 *
 * Triggered when Notifications button is clicked.
 */
void MainWindow::on_actionNotifications_triggered()
{

}

/**
 * @brief MainWindow::on_actionFeed_triggered segues to the Feed view.
 *
 * Triggered when Feed button is clicked.
 */
void MainWindow::on_actionFeed_triggered()
{

}

/**
 * @brief MainWindow::on_actionLog_out_triggered logs the user out.
 *
 * Triggered when Log out button is clicked.
 */
void MainWindow::on_actionLog_out_triggered()
{

}

/**
 * @brief MainWindow::on_actionGroups_triggered segues to the Group view.
 *
 * Triggered when Group button is clicked.
 */
void MainWindow::on_actionGroups_triggered()
{

}
