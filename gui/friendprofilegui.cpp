#include "friendprofilegui.h"
#include "ui_friendprofilegui.h"

FriendProfileGUI::FriendProfileGUI(ProfileInfoType info, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FriendProfileGUI)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();

    ui->userName->setText("Username: " + std::get<1>(info));
    ui->description->setText(std::get<3>(info));
    ui->photo->setScene(scene);
    QPixmap *file = new QPixmap(std::get<2>(info));
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    scene->addItem(image);
    ui->photo->fitInView(image);

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
