#include "dashboardgui.h"
#include "ui_dashboardgui.h"

DashboardGUI::DashboardGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DashboardGUI)
{
    ui->setupUi(this);
}

DashboardGUI::~DashboardGUI()
{
    delete ui;
}

void DashboardGUI::on_latestScrapbookButton_clicked()
{

}
