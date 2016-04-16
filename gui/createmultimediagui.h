#ifndef CREATEMULTIMEDIAGUI_H
#define CREATEMULTIMEDIAGUI_H

#include <QWidget>

namespace Ui {
class CreateMultimediaGUI;
}

class CreateMultimediaGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateMultimediaGUI(QWidget *parent = 0);
    ~CreateMultimediaGUI();

private:
    Ui::CreateMultimediaGUI *ui;
};

#endif // CREATEMULTIMEDIAGUI_H
