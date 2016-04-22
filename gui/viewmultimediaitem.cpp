#include "viewmultimediaitem.h"
#include "ui_viewmultimediaitem.h"

ViewMultimediaItem::ViewMultimediaItem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewMultimediaItem)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->mediaView->setScene(scene);
    mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    //ui->mediaView->setSceneRect(0,0,ui->mediaView->frameSize().width(),ui->mediaView->frameSize().height());

}

ViewMultimediaItem::~ViewMultimediaItem()
{

    delete ui;
}

void ViewMultimediaItem::on_returnButton_clicked()
{
    mediaPlayer->stop();
    this->close();
}

void ViewMultimediaItem::loadPhoto() {

    QPixmap *file = new QPixmap(path);
    QGraphicsPixmapItem *image = new QGraphicsPixmapItem(*file);
    ui->mediaView->fitInView(image);
    scene->addItem(image);
}

void ViewMultimediaItem::loadVideo() {

    QGraphicsVideoItem *videoItem = new QGraphicsVideoItem();
    videoItem->setPos(100,100);
    scene->addItem(videoItem);

    mediaPlayer->setMedia(QUrl::fromLocalFile(path));
    mediaPlayer->play();
    mediaPlayer->setVideoOutput(videoItem);
}

void ViewMultimediaItem::setPath(QString path) {

    this->path = path;

    // clear the current view
    scene->clear();
    ui->mediaView->viewport()->update();
    ui->mediaView->setScene(scene);

    // check whether image or video is displayed
    if (path.contains(".png") || path.contains(".jpg") || path.contains(".bmp")) {
        loadPhoto();
    }
    else if (path.contains(".mp3") || path.contains(".mp4") || path.contains(".flv")) {
        loadVideo();
    }
}
