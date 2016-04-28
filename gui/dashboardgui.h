#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include <QListWidget>
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
    void refreshAllPosts();

private slots:
    void on_latestScrapbookButton_clicked();

    void displayBlog(Blog* blog, QListWidget* theList);
    void displayTweet(Tweet* tweet, QListWidget* theList);
    void displayMultimedia(Multimedia* multimedia, QListWidget* theList);

    void on_latestMultimediaButton_clicked();

private:
    Ui::DashboardGUI *ui;
    AccountController* accountController;
};

#endif // DASHBOARDGUI_H
