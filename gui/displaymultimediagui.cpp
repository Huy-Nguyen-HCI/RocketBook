#include "displaymultimediagui.h"
#include "ui_displaymultimediagui.h"

DisplayMultimediaGUI::DisplayMultimediaGUI(AccountController *inputAcc, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayMultimediaGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAcc;
}

DisplayMultimediaGUI::~DisplayMultimediaGUI()
{
    delete ui;
}

void DisplayMultimediaGUI::on_postButton_clicked()
{
    scrapbook->switchMultimediaViews();
}

void DisplayMultimediaGUI::refreshMultimedia() {

    Profile *currentProfile = accountController->getUser()->getProfile();
    Scrapbook *myScrapbook = currentProfile->getScrapbook();
    std::vector<Multimedia*> allMulti = myScrapbook->getAllMedia();

    ui->multimediaList->clear();

    for (int i = 0; i < allMulti.size(); i++) {

        Multimedia *media = allMulti.at(i);
        QString username = accountController->getUser()->getUsername();
        QString title = media->getTitle();
        QString description = media->getDescription();
        QString content = media->getContent();
        QString num = QString::number(i + 1);

        QString item =
                "Multimedia # " + num + ":" + "\n" +
                "Title:     " + title + "\n" +
                "Content:       " + content + "\n" +
                "Description:       " + description + "\n";


        //QString newLabel = new QString("Title: "+title + "\n" + "Descrption: " + description);
        QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
        //QPicture *newPic = new QPicture(-1);
        //newPic.load(content);
        QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->multimediaList);

        //QListWidgetItem *newMedia = new QListWidgetItem(newPic, description, ui->multimediaList);
        //QListWidgetItem *newMedia = new QListWidgetItem(QImage(content), description, ui->multimediaList);
        ui->multimediaList->addItem(newMedia);

        ui->multimediaList->setIconSize(QSize(200,200));

        //ui->multimediaList->addItem(item);
    }

}

void DisplayMultimediaGUI::on_loadButton_clicked()
{
    refreshMultimedia();
}
