#include "groupprofilegui.h"
#include "ui_groupprofilegui.h"

GroupProfileGUI::GroupProfileGUI(Profile* profile, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupProfileGUI)
{
    ui->setupUi(this);
    photoScene = new QGraphicsScene();
    this->groupProfile = profile;

    refreshProfile();
}

GroupProfileGUI::~GroupProfileGUI()
{
    delete ui;
}

void GroupProfileGUI::refreshProfile()
{
    groupName = groupProfile->getFullName();
    groupDescription = groupProfile->getDescription();
    photoPath = groupProfile->getPicturePath();

    this->setWindowTitle(groupName + "'s Profile");
    ui->groupNameLabel->setText(groupName);
    ui->descriptionBrowser->setText(groupDescription);
    loadPhoto();

}

void GroupProfileGUI::loadPhoto() {
    ui->groupPhoto->setScene(photoScene);
    QPixmap *file = new QPixmap(photoPath);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->groupPhoto->fitInView(image, Qt::KeepAspectRatio);
    photoScene->addItem(image);
}
