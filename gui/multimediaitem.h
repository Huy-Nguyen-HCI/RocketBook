#ifndef MULTIMEDIAITEM_H
#define MULTIMEDIAITEM_H

#include <QDialog>
#include "displaymultimediagui.h"
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
//#include <QMediaPlayer>
//#include <QGraphicsVideoItem>

class DisplayMultimediaGUI;

namespace Ui {
class MultimediaItem;
}

class MultimediaItem : public QDialog
{
    Q_OBJECT

public:
    explicit MultimediaItem(QString username, QString title, QString description, QString path, QWidget *parent = 0);
    ~MultimediaItem();
    void loadPhoto();
    void loadVideo();

private slots:


private:
    Ui::MultimediaItem *ui;
    QString path;
    QGraphicsScene *scene;
};

#endif // MULTIMEDIAITEM_H
