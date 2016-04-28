#ifndef DASHBOARDGUI_H
#define DASHBOARDGUI_H

#include <QWidget>
#include <QListWidget>
#include "../model/accountcontroller.h"
#include "viewbloggui.h"

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

    void on_commentButton_clicked();

    void on_wholeFeedItem_clicked(QListWidgetItem* listItem);

private:
    Ui::DashboardGUI *ui;
    AccountController* accountController;

    //All list item static value for setData --> should be bypassed if redesigned by changing the data structure
    static int blogListItemType;
    static int tweetListItemType;
    static int multimediaListItemType;
    static int listItemTypeRole;
    static int listItemIDRole;
    static int listItemScrapbookRole;
};

#endif // DASHBOARDGUI_H
