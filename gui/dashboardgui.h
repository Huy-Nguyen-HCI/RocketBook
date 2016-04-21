#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"

namespace Ui {
class DashboardGUI;
}

class DashboardGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardGUI(AccountController *inputAccountController, QWidget *parent = 0);
    ~DashboardGUI();

private slots:
    void on_latestScrapbookButton_clicked();

private:
    Ui::DashboardGUI *ui;
    AccountController* accountController;
};

#endif // DASHBOARDGUI_H
