#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;

    scene = new QGraphicsScene();

}

ProfileGUI::~ProfileGUI()
{
    delete scene;
    delete ui;
}


void ProfileGUI::loadProfile() {

    Profile *currentProfile = accountController->getUser()->getProfile();

    QString descr = currentProfile->getDescription();
    QString myName = currentProfile->getFullName();
    photoPath = currentProfile->getPicturePath();
    //qDebug() << "path is: " << photoPath;

    ui->descriptionBox->setText(descr);
    ui->username->setText("Username: " + myName);
    updatePhoto();
}


void ProfileGUI::on_selectPicture_clicked()
{
    photoPath = QFileDialog::getOpenFileName(this,
                                         tr("Pick your image"),
                                         ":/",
                                         tr("Image Files (*.png *.jpg *.bmp)"));
    // if user cancels the file selection
    if (photoPath.isNull()) {
        return;
    }


    //copies the picture the user uploaded to the database, so it is accessible and in a uniform location
    QString username = accountController->getUser()->getUsername();

    QString newPath(AccountController::PATH + "picturesDir/" + username + "Pic");
    QFile newPic(photoPath);

    // if there's already a file at newPath, replace it
    if (QFile::exists(newPath)) {
        QFile::remove(newPath);
    }
    // copy the new image to the new path
    newPic.copy(photoPath, newPath);

    // update the path in the database
    accountController->getUser()->getProfile()->setPicturePath(photoPath);
    accountController->getUser()->changePhoto(newPath);
    //qDebug() << "new path is: " << newPath;

    updatePhoto();

    ui->message->setText("Update photo successful!");



}

void ProfileGUI::on_saveDescription_clicked()
{
    QString newDescription = ui->descriptionBox->toPlainText();
    if (accountController->getUser()->changeProfileDescription(newDescription)) {
        ui->message->setText("Update description successful!");
    }
    else {
        ui->message->setText("Update failed. Please call technical support.");
    }
}

void ProfileGUI::updatePhoto() {

    if (photoPath.isNull()) return;

    // clear the current view
    scene->clear();
    ui->photo->viewport()->update();

    // display the image in the GUI
    ui->photo->setScene(scene);   
    QPixmap *file = new QPixmap(photoPath);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->photo->fitInView(image, Qt::KeepAspectRatio);
    scene->addItem(image);
}
