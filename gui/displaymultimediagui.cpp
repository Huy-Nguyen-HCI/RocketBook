#include "displaymultimediagui.h"
#include "ui_displaymultimediagui.h"

DisplayMultimediaGUI::DisplayMultimediaGUI(Scrapbook *inputScrapbook, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayMultimediaGUI)
{
    ui->setupUi(this);
    scrapbookGUI = input;
    scrapbook = inputScrapbook;
//    viewMedia = new ViewMultimediaItem();
    refreshMultimedia();
    //hide all unimplemented functions
    ui->deleteButton->hide();
    ui->viewButton->hide();
    ui->editButton->hide();
}

DisplayMultimediaGUI::~DisplayMultimediaGUI()
{
    delete ui;
}

void DisplayMultimediaGUI::on_postButton_clicked()
{
    scrapbookGUI->switchMultimediaViews();
}

void DisplayMultimediaGUI::refreshMultimedia() {

    // get all the media from the database
    allMulti = scrapbook->getAllMedia();

    // clear the current view
    ui->multimediaList->clear();

    // add all media to the view again
    for (unsigned int i = 0; i < allMulti.size(); i++) {

        Multimedia *media = allMulti.at(i);
        QString username = media->getAuthorUsername();
        QString title = media->getTitle();
        QString description = media->getDescription();
        QString content = media->getContent();
        QString num = QString::number(i + 1);

        QString item =
                "Multimedia # " + num + ":" + "\n" +
                "Title:     " + title + "\n" +
                "Content:       " + content + "\n" +
                "Description:       " + description + "\n";

        QString newLabel("Title: "+title + "\n" + "Descrption: " + description);
        QListWidgetItem *newMedia = new QListWidgetItem(QIcon(content), newLabel, ui->multimediaList);

        ui->multimediaList->addItem(newMedia);
    }

    ui->multimediaList->setIconSize(QSize(200,200));

}


void DisplayMultimediaGUI::on_loadButton_clicked()
{
    refreshMultimedia();
}

void DisplayMultimediaGUI::on_viewButton_clicked()
{
//    QList<QListWidgetItem *> selected = ui->multimediaList->selectedItems();
//    if (selected.length() == 0) {
//        ui->message->setText("You have to select an item to proceed.");
//        return;
//    }

//    int selectedIndex = ui->multimediaList->row(selected.at(0));
//    Multimedia *media = allMulti[selectedIndex];

//    //qDebug() << "path is: " << media->getContent();
//    viewMedia->show();
//    viewMedia->setPath(media->getContent());
}

void DisplayMultimediaGUI::on_editButton_clicked()
{
    QList<QListWidgetItem *> selected = ui->multimediaList->selectedItems();
    if (selected.length() == 0) {
        ui->message->setText("You have to select an item to proceed.");
        return;
    }
}

void DisplayMultimediaGUI::on_deleteButton_clicked()
{
    QList<QListWidgetItem *> selected = ui->multimediaList->selectedItems();
    if (selected.length() == 0) {
        ui->message->setText("You have to select an item to proceed.");
        return;
    }

}
