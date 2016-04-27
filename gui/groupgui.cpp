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

    ui->returnButton->hide();
    ui->stackedWidget->setCurrentWidget(displayGroupView);
}

GroupGUI::~GroupGUI()
{
    delete ui;
    delete displayGroupView;
    delete createGroupView;
}

void GroupGUI::switchGroupViews(GroupGUIType type)
{
    switch (type){
        case ShowAllGroups:
            ui->stackedWidget->setCurrentWidget(displayGroupView);
            break;
        case CreateGroup:
            ui->stackedWidget->setCurrentWidget(createGroupView);
            break;
        case EditGroup:
            break;
        case ViewGroup:
            ui->stackedWidget->setCurrentWidget(currentGroupView);
            break;
    }
}

void GroupGUI::addWidget(ScrapbookGUI* groupWidget) {
    this->currentGroupView = groupWidget;
    ui->stackedWidget->addWidget(currentGroupView);
    ui->stackedWidget->setCurrentWidget(currentGroupView);
}

void GroupGUI::showReturnButton() {
    ui->returnButton->show();
}

void GroupGUI::on_returnButton_clicked()
{
    ui->returnButton->hide();
    ui->stackedWidget->removeWidget(currentGroupView);
    ui->stackedWidget->setCurrentWidget(displayGroupView);
    delete currentGroupView;
}
