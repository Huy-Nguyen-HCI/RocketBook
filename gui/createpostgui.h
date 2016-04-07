#ifndef CREATEPOSTGUI_H
#define CREATEPOSTGUI_H

#include <QWidget>

namespace Ui {
class CreatePostGUI;
}

class CreatePostGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreatePostGUI(QWidget *parent = 0);
    ~CreatePostGUI();

private:
    Ui::CreatePostGUI *ui;
};

#endif // CREATEPOSTGUI_H
