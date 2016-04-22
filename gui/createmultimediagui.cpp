#include "createmultimediagui.h"
#include "ui_createmultimediagui.h"

CreateMultimediaGUI::CreateMultimediaGUI(AccountController *inputAcc, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMultimediaGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAcc;
}

CreateMultimediaGUI::~CreateMultimediaGUI()
{
    delete ui;
}

void CreateMultimediaGUI::on_returnButton_clicked()
{
    scrapbook->switchMultimediaViews();
}

void CreateMultimediaGUI::on_uploadVideoButton_clicked()
{
    QString inputPath =
            QFileDialog::getOpenFileName(this,
                                         tr("Pick your video"),
                                         ":/",
                                         tr("Video Files (*.mp3 *.mp4 *.flv)"));
    // if user cancels the file selection
    if (inputPath.isNull()) return;

    // change the absolute path to relative file path
    QDir dir("./");
    filePath = dir.relativeFilePath(inputPath);

    ui->filePathBox->setText(filePath);
    ui->message->setText("Choose video file successful!");

}

void CreateMultimediaGUI::on_uploadPhotoButton_clicked()
{
    QString inputPath =
            QFileDialog::getOpenFileName(this,
                                         tr("Pick your image"),
                                         ":/",
                                         tr("Video Files (*.jpg *.gif *.png)"));
    // if user cancels the file selection
    if (inputPath.isNull()) return;

    // change the absolute path to relative file path
    QDir dir("./");
    filePath = dir.relativeFilePath(inputPath);

    ui->filePathBox->setText(filePath);
    ui->message->setText("Choose image file successful!");

    QString usersname = accountController->getUser()->getUsername();
    int picnum = accountController->getUser()->getProfile()->getScrapbook()->getAllMedia().size();
    QString numpic = QString::number(picnum);
    QString newPath("../database//picturesDir/"+usersname+"MultimediaPic_"+numpic);
    QFile newPic(filePath);
    newPic.copy(filePath, newPath);
    filePath = newPath;
}


void CreateMultimediaGUI::on_filePathBox_returnPressed()
{
    // save the file path
    filePath = ui->filePathBox->text();
}



void CreateMultimediaGUI::on_publishButton_clicked()
{
    // prepare data
    RocketUser *user = accountController->getUser();
    QString username = user->getUsername();
    QString title = ui->titleBox->text();
    QString description = ui->descriptionBox->toPlainText();
    int privacy = ui->privacyBox->isChecked();

    // save data to database
    accountController->getUser()->getProfile()->getScrapbook()->addMedia(username, title, description, filePath, privacy);
    scrapbook->switchMultimediaViews();
}
