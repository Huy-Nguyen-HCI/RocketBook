#ifndef DISPLAYMULTIMEDIAGUI_H
#define DISPLAYMULTIMEDIAGUI_H

#include <QDebug>

#include <QWidget>
#include <QListWidgetItem>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"
#include "viewmultimediaitem.h"
//#include "multimediaitem.h"

class MultimediaItem;
class ScrapbookGUI;

namespace Ui {
class DisplayMultimediaGUI;
}

class DisplayMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayMultimediaGUI(AccountController *inputAcc, ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayMultimediaGUI();
    void refreshMultimedia();

private slots:
    void on_postButton_clicked();

    void on_loadButton_clicked();

    void on_viewButton_clicked();

    void on_editButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::DisplayMultimediaGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
    std::vector<Multimedia*> allMulti;
    ViewMultimediaItem *viewMedia;
};

#endif // DISPLAYMULTIMEDIAGUI_H
