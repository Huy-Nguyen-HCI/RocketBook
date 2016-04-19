#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>

namespace Ui {
class ProfileGUI;
}

class ProfileGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileGUI(QWidget *parent = 0);
    ~ProfileGUI();

private:
    Ui::ProfileGUI *ui;
};

#endif // PROFILEGUI_H
