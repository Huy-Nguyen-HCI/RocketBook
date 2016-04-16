#ifndef CREATETWEETGUI_H
#define CREATETWEETGUI_H

#include <QWidget>

namespace Ui {
class CreateTweetGUI;
}

class CreateTweetGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateTweetGUI(QWidget *parent = 0);
    ~CreateTweetGUI();

private:
    Ui::CreateTweetGUI *ui;
};

#endif // CREATETWEETGUI_H
