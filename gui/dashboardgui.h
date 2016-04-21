#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>

namespace Ui {
class DashboardGUI;
}

class DashboardGUI : public QWidget
{
    Q_OBJECT

public:
    explicit DashboardGUI(QWidget *parent = 0);
    ~DashboardGUI();

private slots:
    void on_latestScrapbookButton_clicked();

private:
    Ui::DashboardGUI *ui;
};

#endif // DASHBOARDGUI_H
