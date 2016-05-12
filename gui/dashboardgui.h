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
    /**
     * @brief DashboardGUI the class constructor.
     * @param inputAccountController the input pointer to an AccountController that stores information about the user.
     * @param parent the parent QListWidget.
     */
    explicit DashboardGUI(AccountController *inputAccountController, QWidget *parent = 0);

    /**
      * @brief ~DashboardGUI the class destructor.
      *
      * Delete the pointer to the ui.
      */
    ~DashboardGUI();

    /**
     * @brief refreshAllPosts clear and display all the available posts in the dashboard.
     */
    void refreshAllPosts();

private slots:
    /**
     * @brief on_latestScrapbookButton_clicked load the latest posts by the user.
     */
    void on_latestScrapbookButton_clicked();

    /**
     * @brief displayBlog display a blog in the specified ListWidget.
     * @param blog the blog to be displayed.
     * @param theList the list to include the blog.
     */
    void displayBlog(Blog* blog, QListWidget* theList);

    /**
     * @brief displayTweet display a tweet in the specified ListWidget.
     * @param tweet the tweet to be displayed.
     * @param theList the list to include the tweet.
     */
    void displayTweet(Tweet* tweet, QListWidget* theList);

    /**
     * @brief displayMultimedia display a media content in the specified ListWidget.
     * @param multimedia the media to be displayed.
     * @param theList the list to include the media.
     */
    void displayMultimedia(Multimedia* multimedia, QListWidget* theList);

    /**
     * @brief on_latestMultimediaButton_clicked load and display all the latest media posted by the user.
     */
    void on_latestMultimediaButton_clicked();

    /**
     * @brief on_commentButton_clicked segue to the comment view of the selected blog.
     */
    void on_commentButton_clicked();

    /**
     * @brief wholeFeedItem_clicked show or hide comment button depending on the item clicked.
     *
     * If a blog is selected, the comment button appears; otherwise it is hidden.
     * @param listItem the list to check for selected item.
     */
    void wholeFeedItem_clicked(QListWidgetItem* listItem);

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
