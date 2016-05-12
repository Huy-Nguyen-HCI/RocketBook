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

/**
 * @brief The GroupProfileGUI class provides a view for the group profile
 */
class GroupProfileGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief GroupProfileGUI default constructor
     * @param group The group to be displayed
     * @param parent
     */
    explicit GroupProfileGUI(Group *group, QWidget *parent = 0);

    ~GroupProfileGUI();

private:
    Ui::GroupProfileGUI *ui;
    Group* group;
    QGraphicsScene* photoScene;
    QString groupName;
    QString groupDescription;
    QString photoPath;

    /**
     * @brief refreshProfile Refresh the profile of the group
     */
    void refreshProfile();

    /**
     * @brief loadPhoto Load the photo of the group
     */
    void loadPhoto();

    /**
     * @brief refreshMembers Refresh the member list
     */
    void refreshMembers();

};

#endif // GROUPPROFILEGUI_H
