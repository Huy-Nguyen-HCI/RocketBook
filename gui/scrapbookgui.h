#ifndef SCRAPBOOKGUI_H
#define SCRAPBOOKGUI_H

#include <QWidget>
#include "../model/accountcontroller.h"
#include "createbloggui.h"
#include "createmultimediagui.h"
#include "createtweetgui.h"
#include "displaybloggui.h"
#include "displaymultimediagui.h"
#include "displaytweetgui.h"


class CreateTweetGUI;
class DisplayTweetGUI;
class CreateBlogGUI;
class DisplayBlogGUI;
class CreateMultimediaGUI;
class DisplayMultimediaGUI;

namespace Ui {
class ScrapbookGUI;
}

/**
 * @brief The ScrapbookGUI class is a parent class of all scrapbook functionalities in the GUI
 */
class ScrapbookGUI : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief ScrapbookGUI
     * This constructor is used for personal scrapbooks.
     * It will find the scrapbook in the account controller and retrieve the data from there.
     * @param inputAccountController The current account controller functionality
     * @param parent
     */
    explicit ScrapbookGUI(AccountController *inputAccountController,
                          QWidget *parent = 0);

    /**
     * @brief ScrapbookGUI
     * This constructor is used for any scrapbook
     * @param inputAccountController The current account controller, reflecting the current user
     * @param displayScrapbook The scrapbook that is displaying
     * @param parent
     */
    explicit ScrapbookGUI(AccountController *inputAccountController,
                          Scrapbook* displayScrapbook,
                          QWidget *parent = 0);
    ~ScrapbookGUI();

    /**
     * @brief switchTweetViews
     * Switching between create tweet and tweet view
     */
    void switchTweetViews();

    /**
     * @brief switchBlogViews
     * Switching between create blog and blog view
     */
    void switchBlogViews();

    /**
     * @brief switchMultimediaViews
     * Switching between create multimedia and multimedia view
     */
    void switchMultimediaViews();

    /**
     * @brief refreshBook
     * Refresh the entire scrapbook and display it in the GUI again
     */
    void refreshBook();

    /**
     * @brief displayBlog
     * Display one blog in the scrapbook area
     * @param blog The blog to be displayed
     */
    void displayBlog(Blog* blog);

    /**
     * @brief displayTweet
     * Display one tweet in the scrapbook area
     * @param tweet The tweet to be displayed
     */
    void displayTweet(Tweet* tweet);

    /**
     * @brief displayMultimedia
     * Display one photo/video in the scrapbook area
     * @param multimedia The item to be displayed
     */
    void displayMultimedia(Multimedia* multimedia);

    /**
     * @brief getAccountController
     * @return the current account
     */
    AccountController* getAccountController() { return accountController;}

    /**
     * @brief printPost
     * Detect the post
     * @return the string to print to scrapbook
     */
    QString printPost(Post*);

private slots:

    /**
     * @brief on_editButton_clicked
     */
    void on_editButton_clicked();

    /**
     * @brief on_deleteButton_clicked
     */
    void on_deleteButton_clicked();

    /**
     * @brief on_viewButton_clicked
     * Open a new window to view blog
     */
    void on_viewButton_clicked();

    /**
     * @brief scrapbookAreaItem_clicked
     * The slot to be connected to scrapbook area item clicked, and so that the comment button appears.
     * @param listItem
     */
    void scrapbookAreaItem_clicked(QListWidgetItem *listItem);

    /**
     * @brief on_exportButton_clicked
     * Export the current scrapbook to HTML
     */
    void on_exportButton_clicked();

    /**
     * @brief on_refreshButton_clicked
     */
    void on_refreshButton_clicked();



private:
    Ui::ScrapbookGUI *ui;
    CreateBlogGUI *createBlogView;
    CreateMultimediaGUI *createMultimediaView;
    CreateTweetGUI *createTweetView;
    DisplayBlogGUI *displayBlogView;
    DisplayMultimediaGUI *displayMultimediaView;
    DisplayTweetGUI *displayTweetView;
    AccountController *accountController;
    Scrapbook* scrapbook;



    //All list item static value for setData --> should be bypassed if redesigned by changing the data structure
    static int blogListItemType;
    static int tweetListItemType;
    static int multimediaListItemType;
    static int listItemTypeRole;
    static int listItemIDRole;

    /**
     * @brief setUp Set up the constructor
     */
    void setUp();

    /**
     * @brief writeToHTMLFile
     * @param htmlText
     */
    void writeToHTMLFile(QString htmlText);


};

#endif // SCRAPBOOKGUI_H
