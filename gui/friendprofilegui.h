#ifndef FRIENDPROFILEGUI_H
#define FRIENDPROFILEGUI_H

#include <QDialog>
#include "../model/profile.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class FriendProfileGUI;
}

class FriendProfileGUI : public QDialog
{
    Q_OBJECT

public:
    explicit FriendProfileGUI(ProfileInfoType info, QWidget *parent = 0);
    ~FriendProfileGUI();

private slots:
    void on_returnButton_clicked();

private:
    Ui::FriendProfileGUI *ui;
    QGraphicsScene *scene;
};

#endif // FRIENDPROFILEGUI_H
