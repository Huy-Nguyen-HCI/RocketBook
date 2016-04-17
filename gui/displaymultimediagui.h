#ifndef DISPLAYMULTIMEDIAGUI_H
#define DISPLAYMULTIMEDIAGUI_H

#include <QWidget>
#include "scrapbookgui.h"

class ScrapbookGUI;

namespace Ui {
class DisplayMultimediaGUI;
}

class DisplayMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayMultimediaGUI(ScrapbookGUI *input, QWidget *parent = 0);
    ~DisplayMultimediaGUI();

private slots:
    void on_postButton_clicked();

private:
    Ui::DisplayMultimediaGUI *ui;
    ScrapbookGUI *scrapbook;
};

#endif // DISPLAYMULTIMEDIAGUI_H
