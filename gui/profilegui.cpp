#include "profilegui.h"
#include "ui_profilegui.h"

ProfileGUI::ProfileGUI(AccountController *inputAccountController, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProfileGUI)
{
    ui->setupUi(this);
    accountController = inputAccountController;
    scene = new QGraphicsScene(this);

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

    ui->descriptionBox->setText(descr);
    ui->username->setText("Username: " + myName);
    updatePhoto(currentProfile->getPicturePath());
    std::cout << currentProfile->getPicturePath().toStdString() << std::endl;
}


void ProfileGUI::on_selectPicture_clicked()
{
    QString filePath =
            QFileDialog::getOpenFileName(this,
                                         tr("Pick your image"),
                                         ":/",
                                         tr("Image Files (*.png *.jpg *.bmp)"));
    // if user cancels the file selection
    if (filePath.isNull()) {
        return;
    }

    // change the absolute path to relative file path
    QDir dir("./");
    QString path = dir.relativeFilePath(filePath);

    std::cout << "path is : " + path.toStdString() << std::endl;

    // update the path in the database
    accountController->getUser()->getProfile()->setPicturePath(path);
    accountController->getUser()->changePhoto(path);

    updatePhoto(path);

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

void ProfileGUI::updatePhoto(QString filePath) {
    // clear the current view
    scene->clear();
    ui->photo->viewport()->update();

    // display the image in the GUI
    ui->photo->setScene(scene);
    QPixmap *file = new QPixmap(filePath);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    scene->addItem(image);
    ui->photo->fitInView(image);
}
