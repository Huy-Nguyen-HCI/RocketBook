#ifndef CREATEMULTIMEDIAGUI_H
#define CREATEMULTIMEDIAGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class CreateMultimediaGUI;
}

class CreateMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMultimediaGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~CreateMultimediaGUI();

private slots:
    void on_returnButton_clicked();

private:
    Ui::CreateMultimediaGUI *ui;
    ScrapbookGUI *scrapbook;
};


#endif // CREATEMULTIMEDIAGUI_H
