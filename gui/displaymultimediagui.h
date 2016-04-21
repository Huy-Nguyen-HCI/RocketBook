#ifndef DISPLAYMULTIMEDIAGUI_H
#define DISPLAYMULTIMEDIAGUI_H

#include <QWidget>
#include "scrapbookgui.h"
#include "../model/accountcontroller.h"

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

private:
    Ui::DisplayMultimediaGUI *ui;
    ScrapbookGUI *scrapbook;
    AccountController *accountController;
};

#endif // DISPLAYMULTIMEDIAGUI_H
