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
    ui->groupSwitchButton->hide();
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
            ui->returnButton->hide();
            ui->groupSwitchButton->hide();
            break;
        case CreateGroup:
            ui->stackedWidget->setCurrentWidget(createGroupView);
            ui->returnButton->hide();
            ui->groupSwitchButton->hide();
            break;
        case ViewGroupProfile:
            ui->stackedWidget->setCurrentWidget(groupProfileView);
            ui->returnButton->show();
            ui->groupSwitchButton->setText("Group Scrapbook");
            ui->groupSwitchButton->show();
            break;
        case EnterScrapbook:
            ui->stackedWidget->setCurrentWidget(currentGroupView);
            ui->returnButton->show();
            ui->groupSwitchButton->setText("Group Profile");
            ui->groupSwitchButton->show();
            break;
    }
}

void GroupGUI::addGroupScrapbook(ScrapbookGUI* groupWidget) {
    this->currentGroupView = groupWidget;
    ui->stackedWidget->addWidget(currentGroupView);
//    ui->stackedWidget->setCurrentWidget(currentGroupView);
}

void GroupGUI::addGroupProfile(GroupProfileGUI *profileView) {
    this->groupProfileView = profileView;
    ui->stackedWidget->addWidget(groupProfileView);
//    ui->stackedWidget->setCurrentWidget(groupProfileView);
}


void GroupGUI::on_returnButton_clicked()
{
    ui->stackedWidget->removeWidget(currentGroupView);
    delete currentGroupView;

    ui->stackedWidget->removeWidget(groupProfileView);
    delete groupProfileView;

    switchGroupViews(ShowAllGroups);
}


void GroupGUI::on_groupSwitchButton_clicked()
{
    if (ui->stackedWidget->currentWidget() == currentGroupView) {
        switchGroupViews(ViewGroupProfile);
    } else {
        switchGroupViews(EnterScrapbook);

    }

}
