#include "multimediaitem.h"
#include "ui_multimediaitem.h"

MultimediaItem::MultimediaItem(QString username, QString title, QString description, QString path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MultimediaItem)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->mediaView->setScene(scene);
    this->setStyleSheet("border: 1px solid black");

    this->path = path;

    ui->title->setText(title);
    ui->description->setText(description);
    ui->username->setText(username);

    // check the file extension
    if (path.contains(".png") || path.contains(".jpg") || path.contains(".bmp")) {
        loadPhoto();
    }
    else if (path.contains(".mp3") || path.contains(".mp4") || path.contains(".flv")) {
        loadVideo();
    }

}

MultimediaItem::~MultimediaItem()
{
    delete ui;
}


void MultimediaItem::loadPhoto() {

    QPixmap *file = new QPixmap(path);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->mediaView->fitInView(image);
    scene->addItem(image);
}

void MultimediaItem::loadVideo() {

    QMediaPlayer *mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    QGraphicsVideoItem *videoItem = new QGraphicsVideoItem();
    videoItem->setPos(100,100);
    scene->addItem(videoItem);
    mediaPlayer->setMedia(QUrl::fromLocalFile(path));
    mediaPlayer->play();
    mediaPlayer->setVideoOutput(videoItem);
}
