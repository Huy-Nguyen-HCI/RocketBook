#ifndef CHATGUI_H
#define CHATGUI_H

#include <QWidget>
#include <QDialog>
#include "../model/profile.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <../model/accountcontroller.h>

namespace Ui {
class ChatGUI;
}

class ChatGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ChatGUI(AccountController *input, int chatId, QWidget *parent = 0);
    ~ChatGUI();

private:
    Ui::ChatGUI *ui;
    QGraphicsScene *scene;
};

#endif // CHATGUI_H
