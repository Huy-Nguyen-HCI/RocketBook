#ifndef CREATEGROUPGUI_H
#define CREATEGROUPGUI_H

#include <QWidget>

namespace Ui {
class CreateGroupGUI;
}

class CreateGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateGroupGUI(QWidget *parent = 0);
    ~CreateGroupGUI();

private:
    Ui::CreateGroupGUI *ui;
};

#endif // CREATEGROUPGUI_H
