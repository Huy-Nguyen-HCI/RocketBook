#ifndef PROFILEGUI_H
#define PROFILEGUI_H

#include <QWidget>
#include <QListWidget>
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
    void loadProfile();

private slots:

    void on_selectPicture_clicked();

    void on_saveDescription_clicked();

private:
    Ui::ProfileGUI *ui;
    AccountController *accountController;
};

#endif // PROFILEGUI_H
