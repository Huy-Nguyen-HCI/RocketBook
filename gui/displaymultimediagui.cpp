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

        ui->multimediaList->addItem(item);
    }

}

void DisplayMultimediaGUI::on_loadButton_clicked()
{
    refreshMultimedia();
}
