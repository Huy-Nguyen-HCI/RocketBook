#include "friendprofilegui.h"
#include "ui_friendprofilegui.h"

FriendProfileGUI::FriendProfileGUI(ProfileInfoType info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendProfileGUI)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    QString username = std::get<1>(info);
    photoPath = std::get<2>(info);
    QString description = std::get<3>(info);

    this->setWindowTitle(username + " 's Profile");
    ui->userName->setText("Username: " + username);
    ui->description->setText(description);
}

FriendProfileGUI::~FriendProfileGUI()
{
    delete scene;
    delete ui;
}

void FriendProfileGUI::on_returnButton_clicked()
{
    this->close();
}


void FriendProfileGUI::loadPhoto() {
    ui->photo->setScene(scene);
    QPixmap *file = new QPixmap(photoPath);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->photo->fitInView(image);
    scene->addItem(image);
}
