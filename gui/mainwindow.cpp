#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(AccountController *inputAccountController, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    accountController = inputAccountController;

    ui->setupUi(this);
    dashboard = new DashboardGUI();
    scrapbook = new ScrapbookGUI();
    profile = new ProfileGUI(accountController);

    ui->stackedWidget->addWidget(dashboard);
    ui->stackedWidget->addWidget(scrapbook);
    ui->stackedWidget->addWidget(profile);
}

MainWindow::~MainWindow()
{
    delete ui;
    if (login) delete login;
}



void MainWindow::on_actionFeed_triggered()
{
    ui->stackedWidget->setCurrentWidget(dashboard);
}

void MainWindow::on_actionAboutMe_triggered()
{
    ui->stackedWidget->setCurrentWidget(profile);
}

void MainWindow::on_actionNotifications_triggered()
{

}

void MainWindow::on_actionFriend_triggered()
{

}

void MainWindow::on_actionLog_out_triggered()
{
    login = new LoginGUI(accountController);
    login->setMainWindow(this);
    this->close();
    login->show();
}

void MainWindow::on_actionGroups_triggered()
{

}

void MainWindow::on_actionMessaging_triggered()
{

}

void MainWindow::on_actionScrapbook_triggered()
{
    ui->stackedWidget->setCurrentWidget(scrapbook);
}
