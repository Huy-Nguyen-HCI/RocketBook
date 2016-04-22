#include "displaymultimediagui.h"
#include "ui_displaymultimediagui.h"

DisplayMultimediaGUI::DisplayMultimediaGUI(AccountController *inputAcc, ScrapbookGUI *input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DisplayMultimediaGUI)
{
    ui->setupUi(this);
    scrapbook = input;
    accountController = inputAcc;
//    viewMedia = new ViewMultimediaItem();
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
    allMulti = myScrapbook->getAllMedia();

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

//void DisplayMultimediaGUI::refreshMultimedia() {

//    Profile *currentProfile = accountController->getUser()->getProfile();
//    Scrapbook *myScrapbook = currentProfile->getScrapbook();
//    std::vector<Multimedia*> allMulti = myScrapbook->getAllMedia();

//    ui->multimediaList->clear();

//    for (int i = 0 ; i < allMulti.size(); i++) {

//        // get info
//        Multimedia *media = allMulti.at(i);
//        QString username = accountController->getUser()->getUsername();
//        QString title = media->getTitle();
//        QString description = media->getDescription();
//        QString content = media->getContent();

//        // create items
//        MultimediaItem *mediaItem = new MultimediaItem(username, title, description, content);
//        mediaItem->resize(ui->multimediaList->width(), 100);
//        QListWidgetItem *widgetItem = new QListWidgetItem();
//        mediaItem->layout()->setSizeConstraint(QLayout::SetFixedSize);
//        widgetItem->setSizeHint(mediaItem->sizeHint());

//        // add widget to list
//        ui->multimediaList->addItem(widgetItem);
//        ui->multimediaList->setItemWidget(widgetItem, mediaItem);
//    }
//}

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

//    qDebug() << "path is: " << media->getContent();
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
