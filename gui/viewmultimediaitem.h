#ifndef VIEWMULTIMEDIAITEM_H
#define VIEWMULTIMEDIAITEM_H

#include <QDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include <QGraphicsVideoItem>

namespace Ui {
class ViewMultimediaItem;
}

class ViewMultimediaItem : public QDialog
{
    Q_OBJECT

public:
    explicit ViewMultimediaItem(QWidget *parent = 0);
    ~ViewMultimediaItem();
    void loadPhoto();
    void loadVideo();
    void setPath(QString path);

private slots:
    void on_returnButton_clicked();

private:
    Ui::ViewMultimediaItem *ui;
    QGraphicsScene *scene;
    QMediaPlayer *mediaPlayer;
    QString path;
};

#endif // VIEWMULTIMEDIAITEM_H
