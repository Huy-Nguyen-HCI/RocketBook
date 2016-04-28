#include "groupprofilegui.h"
#include "ui_groupprofilegui.h"

GroupProfileGUI::GroupProfileGUI(Group* group, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupProfileGUI)
{
    ui->setupUi(this);
    photoScene = new QGraphicsScene();
    this->group = group;


    //set up member table
    ui->memberTable->setColumnCount(2);
    ui->memberTable->horizontalHeader()->hide();
    ui->memberTable->verticalHeader()->hide();
    ui->memberTable->setShowGrid(false);
    ui->memberTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->memberTable->setSelectionMode( QAbstractItemView::ExtendedSelection );

    refreshProfile();
}

GroupProfileGUI::~GroupProfileGUI()
{
    delete ui;
}

void GroupProfileGUI::refreshProfile()
{
    //retrieve information
    groupName = group->getProfile()->getFullName();
    groupDescription = group->getProfile()->getDescription();
    photoPath = group->getProfile()->getPicturePath();


    this->setWindowTitle(groupName + "'s Profile");
    ui->groupNameLabel->setText(groupName);
    ui->descriptionBrowser->setText(groupDescription);
    loadPhoto();
    refreshMembers();
}

void GroupProfileGUI::refreshMembers() {
    ui->memberTable->clear();

    std::vector<QString> adminList = group->getAdminNameList();
    std::vector<QString> memberList = group->getMemberNameList();

    ui->memberTable->setRowCount(adminList.size() + memberList.size());

    //display admin list
    for (unsigned int row = 0; row < adminList.size(); row++) {
        QTableWidgetItem* username = new QTableWidgetItem(adminList.at(row));
        QTableWidgetItem* adminRights = new QTableWidgetItem("Administrator");
        ui->memberTable->setItem(row, 0, username);
        username->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        adminRights->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->memberTable->setItem(row, 1, adminRights);
    }

    //display member list
    for (unsigned int row = adminList.size(); row < adminList.size() + memberList.size(); row++) {
        QTableWidgetItem* username = new QTableWidgetItem(memberList.at(row - adminList.size()));
        QTableWidgetItem* adminRights = new QTableWidgetItem("Member");
        username->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        adminRights->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEnabled);
        ui->memberTable->setItem(row, 0, username);
        ui->memberTable->setItem(row, 1, adminRights);
    }

}

void GroupProfileGUI::loadPhoto() {
    ui->groupPhoto->setScene(photoScene);
    QPixmap *file = new QPixmap(photoPath);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->groupPhoto->fitInView(image, Qt::KeepAspectRatio);
    photoScene->addItem(image);
}
