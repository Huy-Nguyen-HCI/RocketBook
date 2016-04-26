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
    messages = new MessageGUI(accountController);
    profile = new ProfileGUI(accountController);
    friends = new FriendsGUI(accountController);
    groups = new GroupGUI(accountController);
    about = new AboutGUI();


    ui->stackedWidget->addWidget(messages);
    ui->stackedWidget->addWidget(dashboard);
    ui->stackedWidget->addWidget(scrapbook);
    ui->stackedWidget->addWidget(profile);
    ui->stackedWidget->addWidget(friends);
    ui->stackedWidget->addWidget(groups);
    ui->stackedWidget->addWidget(about);


    ui->stackedWidget->setCurrentWidget(dashboard);

    this->setWindowTitle("Welcome " + username + "!");
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actionFeed_triggered()
{
    ui->stackedWidget->setCurrentWidget(dashboard);
    dashboard->refreshAllPosts();

}

void MainWindow::on_actionAboutMe_triggered()
{
    ui->stackedWidget->setCurrentWidget(profile);
    profile->loadProfile();
    profile->updatePhoto();
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

    this->close();
}

void MainWindow::on_actionGroups_triggered()
{
    ui->stackedWidget->setCurrentWidget(groups);

}

void MainWindow::on_actionMessaging_triggered()
{
    messages->refreshFriendList();
    messages->refreshChats();
    ui->stackedWidget->setCurrentWidget(messages);
}

void MainWindow::on_actionScrapbook_triggered()
{
    ui->stackedWidget->setCurrentWidget(scrapbook);
    scrapbook->refreshBook();
}

void MainWindow::on_actionAbout_Rocketbook_triggered()
{
    ui->stackedWidget->setCurrentWidget(about);
}
