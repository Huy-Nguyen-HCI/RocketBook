#ifndef CREATEACCOUNTGUI_H
#define CREATEACCOUNTGUI_H

#include <QWidget>
#include "logingui.h"

class LoginGUI;

namespace Ui {
class CreateAccountGUI;
}

class CreateAccountGUI : public QWidget
{
    Q_OBJECT

public:
    explicit CreateAccountGUI(AccountController *input, QWidget *parent = 0);
    void setLoginView(LoginGUI *input) { loginView = input; }
    ~CreateAccountGUI();
    void clearAllFields();

private slots:
    void on_uploadButton_clicked();

    void on_returnButton_clicked();

    void on_createButton_clicked();

private:
    Ui::CreateAccountGUI *ui;
    LoginGUI *loginView;
    AccountController *accountController;
};

#endif // CREATEACCOUNTGUI_H