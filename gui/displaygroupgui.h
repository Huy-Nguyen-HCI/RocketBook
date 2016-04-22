#ifndef DISPLAYGROUPGUI_H
#define DISPLAYGROUPGUI_H

#include <QWidget>

namespace Ui {
class DisplayGroupGUI;
}

class DisplayGroupGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DisplayGroupGUI(QWidget *parent = 0);
    ~DisplayGroupGUI();

private:
    Ui::DisplayGroupGUI *ui;
};

#endif // DISPLAYGROUPGUI_H
