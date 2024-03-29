#include "friendprofilegui.h"
#include "ui_friendprofilegui.h"

FriendProfileGUI::FriendProfileGUI(ProfileInfoType info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendProfileGUI)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    // get the info to display from the database
    QString username = std::get<1>(info);
    photoPath = std::get<2>(info);
    QString description = std::get<3>(info);

    // display the info
    this->setWindowTitle(username + " 's Profile");
    ui->usernameLabel->setText(username);
    ui->descriptionBrowser->setText(description);
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
    ui->photo->fitInView(image, Qt::KeepAspectRatio);
    scene->addItem(image);
}
