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
    explicit GroupProfileGUI(Group *group, QWidget *parent = 0);
    ~GroupProfileGUI();

private:
    Ui::GroupProfileGUI *ui;
    Group* group;
    QGraphicsScene* photoScene;
    QString groupName;
    QString groupDescription;
    QString photoPath;

    void refreshProfile();
    void loadPhoto();
    void refreshMembers();

};

#endif // GROUPPROFILEGUI_H
