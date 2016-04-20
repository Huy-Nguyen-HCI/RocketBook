#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"

namespace Ui {
class ProfileGUI;
}

class ProfileGUI : public QWidget
{
    Q_OBJECT

public:
    explicit ProfileGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~ProfileGUI();

private slots:
    void on_pushButton_loadProfile_clicked();

private:
    Ui::ProfileGUI *ui;
    AccountController *accountController;
};

#endif // PROFILEGUI_H
