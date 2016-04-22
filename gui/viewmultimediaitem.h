#ifndef VIEWMULTIMEDIAITEM_H
#define VIEWMULTIMEDIAITEM_H

#include <QWidget>
#include <QFileDialog>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>
#include <QFile>

namespace Ui {
class ViewMultimediaItem;
}

class ViewMultimediaItem : public QWidget
{
    Q_OBJECT

public:
    explicit ViewMultimediaItem(QWidget *parent = 0);
    ~ViewMultimediaItem();
    void setPath(QString path);
    void loadPhoto();
    void loadVideo();

private slots:

    void on_returnButton_clicked();


private:
    Ui::ViewMultimediaItem *ui;
    QString filePath;
    QGraphicsScene *scene;
    QMediaPlayer *mediaPlayer;
};

#endif // VIEWMULTIMEDIAITEM_H
