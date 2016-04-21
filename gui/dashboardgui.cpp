#include "dashboardgui.h"
#include "ui_dashboardgui.h"

DashboardGUI::DashboardGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGUI)
{
    ui->setupUi(this);
    this->accountController = inputAccountController;
}

DashboardGUI::~DashboardGUI()
{
    delete ui;
}

void DashboardGUI::on_latestScrapbookButton_clicked()
{
    std::vector<Post*> latestScrapbook = accountController->getUser()->getProfile()->getScrapbook()->getLatestPosts(4);

}
