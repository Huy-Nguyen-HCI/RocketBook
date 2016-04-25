#include "groupgui.h"
#include "ui_groupgui.h"

GroupGUI::GroupGUI(AccountController* inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupGUI)
{
    ui->setupUi(this);
    this->accountController = inputAccountController;

    displayGroupView = new DisplayGroupGUI(accountController, this);
    createGroupView = new CreateGroupGUI(accountController, this);

    ui->stackedWidget->addWidget(displayGroupView);
    ui->stackedWidget->addWidget(createGroupView);

    ui->stackedWidget->setCurrentWidget(displayGroupView);
}

GroupGUI::~GroupGUI()
{
    delete ui;
}

void GroupGUI::switchGroupViews()
{
    if(ui->stackedWidget->currentWidget() == displayGroupView) {
        ui->stackedWidget->setCurrentWidget(createGroupView);
    } else {
        ui->stackedWidget->setCurrentWidget(displayGroupView);
    }
}
