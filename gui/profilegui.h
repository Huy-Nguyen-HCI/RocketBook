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

class ProfileGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~ProfileGUI();
    void loadProfile();

private slots:

    void on_selectPicture_clicked();

    void on_saveDescription_clicked();

    void updatePhoto(QString filePath);

private:
    Ui::ProfileGUI *ui;
    AccountController *accountController;
    QGraphicsScene *scene;

};

#endif // PROFILEGUI_H
