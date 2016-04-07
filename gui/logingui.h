#ifndef LOGINGUI_H
#define LOGINGUI_H

#include <QWidget>
#include <string>

namespace Ui {
class LoginGUI;
}

class LoginGUI : public QWidget
{
    Q_OBJECT

public:
    explicit LoginGUI(QWidget *parent = 0);
    ~LoginGUI();

private slots:
    void on_loginButton_clicked();

    void on_createAccountButton_clicked();

private:
    Ui::LoginGUI *ui;
};

#endif // LOGINGUI_H
