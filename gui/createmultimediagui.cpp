#include "createmultimediagui.h"
#include "ui_createmultimediagui.h"

CreateMultimediaGUI::CreateMultimediaGUI(AccountController* currentAccount,
                                         Scrapbook *inputScrapbook,
                                         ScrapbookGUI *input,
                                         QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateMultimediaGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    accountController = currentAccount;
    scrapbook = inputScrapbook;
    ui->uploadVideoButton->hide();
}

CreateMultimediaGUI::~CreateMultimediaGUI()
{
    delete ui;
}

void CreateMultimediaGUI::on_returnButton_clicked()
{
    scrapbookGUI->switchMultimediaViews();
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
    filePath = QFileDialog::getOpenFileName(this,
                                         tr("Pick your image"),
                                         ":/",
                                         tr("Video Files (*.jpg *.bmp *.png)"));
    // if user cancels the file selection
    if (filePath.isNull()) return;

    ui->filePathBox->setText(filePath);
    ui->message->setText("Choose image file successful!");

    //create new file name
    int scrapbookID = scrapbook->getID();
    int picnum = scrapbook->getAllMedia().size();
    QString numScrapbookID = QString::number(scrapbookID);
    QString numpic = QString::number(picnum);

    QString newPath(AccountController::PATH + "picturesDir/" + numScrapbookID + "MultimediaPic_" + numpic);
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
    QString username = accountController->getUser()->getUsername();
    QString title = ui->titleBox->text();
    QString description = ui->descriptionBox->toPlainText();
    int privacy = ui->privacyBox->isChecked();

    // save data to database
    scrapbook->addMedia(username, title, description, filePath, privacy);
    scrapbookGUI->switchMultimediaViews();
}

void CreateMultimediaGUI::clearViews() {

    ui->titleBox->clear();
    ui->descriptionBox->clear();
    ui->filePathBox->clear();
    ui->privacyBox->setChecked(false);
}
