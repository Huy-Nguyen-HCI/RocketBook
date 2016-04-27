#ifndef GROUPPROFILEGUI_H
#define GROUPPROFILEGUI_H

#include <QWidget>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

#include "groupgui.h"

class GroupGUI;

namespace Ui {
class GroupProfileGUI;
}

class GroupProfileGUI : public QWidget
{
    Q_OBJECT

public:
    explicit GroupProfileGUI(Profile *profile, QWidget *parent = 0);
    ~GroupProfileGUI();

private:
    Ui::GroupProfileGUI *ui;
    Profile* groupProfile;
    QGraphicsScene* photoScene;
    QString groupName;
    QString groupDescription;
    QString photoPath;

    void refreshProfile();
    void loadPhoto();

};

#endif // GROUPPROFILEGUI_H
