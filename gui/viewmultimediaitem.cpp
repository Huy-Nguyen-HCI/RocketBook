#include "viewmultimediaitem.h"
#include "ui_viewmultimediaitem.h"

ViewMultimediaItem::ViewMultimediaItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewMultimediaItem)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->mediaView->setScene(scene);
    mediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    ui->mediaView->setSceneRect(0,0,ui->mediaView->frameSize().width(),ui->mediaView->frameSize().height());


}

ViewMultimediaItem::~ViewMultimediaItem()
{
    delete ui;
}



void ViewMultimediaItem::on_returnButton_clicked()
{
    mediaPlayer->pause();
    this->close();
}

void ViewMultimediaItem::loadPhoto() {

}

void ViewMultimediaItem::loadVideo() {

    scene->clear();
    ui->mediaView->viewport()->update();
    // display video
    QGraphicsVideoItem *videoItem = new QGraphicsVideoItem();
    videoItem->setPos(0,0);
    scene->addItem(videoItem);
    ui->mediaView->fitInView(videoItem);
    mediaPlayer->setMedia(QUrl::fromLocalFile(filePath));
    mediaPlayer->play();
    mediaPlayer->setVideoOutput(videoItem);
}

void ViewMultimediaItem::setPath(QString path) {

    // change relative path to absolute path
    QDir dir(path);
    filePath = dir.absolutePath();
    qDebug() << "path right now is: " << filePath;

    // check the file extension
    if (path.contains(".png") || path.contains(".jpg") || path.contains(".bmp")) {
        loadPhoto();
    }
    else if (path.contains(".mp3") || path.contains(".mp4") || path.contains(".flv")) {
        loadVideo();
    }
}
