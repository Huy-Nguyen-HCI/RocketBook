#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QWidget>

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QWidget
{
    Q_OBJECT

public:
    explicit LoginGUI(QWidget *parent = 0);
    ~LoginGUI();

private:
    Ui::LoginGUI *ui;
};

#endif // LOGINGUI_H
