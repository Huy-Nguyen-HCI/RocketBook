#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>
#include <QListWidget>
#include <QFileDialog>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "../model/accountcontroller.h"

namespace Ui {
class ProfileGUI;
}

/**
 * @brief The ProfileGUI class is a view class that displays the profile
 */
class ProfileGUI : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief ProfileGUI
     * Default profileGUI
     * @param inputAccountController the current account
     * @param parent
     */
    explicit ProfileGUI(AccountController *inputAccountController, QWidget *parent = 0);

    ~ProfileGUI();

    /**
     * @brief loadProfile
     */
    void loadProfile();

    /**
     * @brief updatePhoto
     */
    void updatePhoto();

private slots:

    /**
     * @brief on_selectPicture_clicked
     */
    void on_selectPicture_clicked();

    /**
     * @brief on_saveDescription_clicked
     */
    void on_saveDescription_clicked();

private:
    Ui::ProfileGUI *ui;
    AccountController *accountController;
    QGraphicsScene *scene;
    QString photoPath;

};

#endif // PROFILEGUI_H
