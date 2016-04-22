#ifndef DISPLAYMESSAGINGGUI_H
#define DISPLAYMESSAGINGGUI_H

#include <QWidget>

namespace Ui {
class displayMessagingGUI;
}

class displayMessagingGUI : public QWidget
{
    Q_OBJECT

public:
    explicit displayMessagingGUI(QWidget *parent = 0);
    ~displayMessagingGUI();

private:
    Ui::displayMessagingGUI *ui;
};

#endif // DISPLAYMESSAGINGGUI_H
