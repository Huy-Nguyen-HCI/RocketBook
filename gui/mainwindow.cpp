#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(AccountController *inputAccountController, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    accountController = inputAccountController;

    ui->setupUi(this);
    dashboard = new DashboardGUI(accountController);
    scrapbook = new ScrapbookGUI(accountController);
    profile = new ProfileGUI(accountController);
    friends = new FriendsGUI(accountController);

    ui->stackedWidget->addWidget(dashboard);
    ui->stackedWidget->addWidget(scrapbook);
    ui->stackedWidget->addWidget(profile);
    ui->stackedWidget->addWidget(friends);
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
    profile->loadProfile();
    ui->stackedWidget->setCurrentWidget(profile);
}

void MainWindow::on_actionNotifications_triggered()
{

}

void MainWindow::on_actionFriend_triggered()
{
    friends->refreshFriendList();
    ui->stackedWidget->setCurrentWidget(friends);
}

void MainWindow::on_actionLog_out_triggered()
{
//    login = new LoginGUI(accountController);
//    CreateAccountGUI *createAccount = new CreateAccountGUI(accountController);
//    login->setMainWindow(this);
//    login->setCreateAccountView(createAccount);
//    createAccount->setLoginView(login);
//    this->close();
//    login->show();
    this->close();
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
