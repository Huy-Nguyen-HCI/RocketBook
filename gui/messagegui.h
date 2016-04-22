#ifndef MESSAGEGUI_H
#define MESSAGEGUI_H

#include <QWidget>

namespace Ui {
class MessageGUI;
}

class MessageGUI : public QWidget
{
    Q_OBJECT

public:
    explicit MessageGUI(QWidget *parent = 0);
    ~MessageGUI();

private:
    Ui::MessageGUI *ui;
};

#endif // MESSAGEGUI_H
