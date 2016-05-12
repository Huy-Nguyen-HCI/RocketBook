#ifndef FRIENDPROFILEGUI_H
#define FRIENDPROFILEGUI_H

#include <QDialog>
#include "../model/profile.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>

namespace Ui {
class FriendProfileGUI;
}

/**
 * @brief The FriendProfileGUI class displays the friend's profile when viewed in the friend list.
 */
class FriendProfileGUI : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief FriendProfileGUI the class constructor.
     * @param info the type of the profile being displayed.
     * @param parent the parent QWidget class.
     */
    explicit FriendProfileGUI(ProfileInfoType info, QWidget *parent = 0);

    /**
      * @brief ~FriendProfileGUI the class destructor. Deletes the pointer to ui.
      */
    ~FriendProfileGUI();

    /**
     * @brief loadPhoto load the friend's profile photo.
     */
    void loadPhoto();

private slots:
    /**
     * @brief on_returnButton_clicked close this view and return to the main window.
     */
    void on_returnButton_clicked();

private:
    Ui::FriendProfileGUI *ui;
    QGraphicsScene *scene;
    QString photoPath;
};

#endif // FRIENDPROFILEGUI_H
