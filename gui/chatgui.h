#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>

namespace Ui {
class ChatGUI;
}

class ChatGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatGUI(QWidget *parent = 0);
    ~ChatGUI();

private:
    Ui::ChatGUI *ui;
};

#endif // CHATGUI_H
