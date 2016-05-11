#ifndef POSTUI_H
#define POSTUI_H

#include "screen.h"

/**
 * @brief Scrapbook UI handles all of the functions for scrapbook in text UI
 */


class ScrapbookUI: public Screen
{
public:
    /**
     * @brief ScrapbookIU
     * @param accountController Account Controller
     *
     */
    ScrapbookUI(AccountController* accountControl);
    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    void drawScreen(int v);
    /**
     * @brief Take command
     * Makes new screen based on user selection
     * @param selection Pointer value when enter is pressed
     */
    void takeCommand(int selection);

    /**
     * @brief Post Blog
     * Asks user for blog title and contents and creates blog post
     */
    void postBlog();
    /**
     * @brief Post Tweet
     * Asks user to enter text and creates tweet post
     */
    void postTweet();
    /**
     * @brief Generates HTML Scrapbook
     */
    void makeHTML();
    /**
     * @brief View Scrapbook
     * Displays scrapbook posts on screen and allows user to scroll and select blogs to comment
     * @return location of pointer on screen
     */
    int displayScrapbook();
    /**
     * @brief View Blog
     * Displays selected blog on screen
     * @param index Index of selected blog
     */
    void viewBlog(int index);
    /**
     * @brief Post Tweet
     * Asks user to enter text and creates tweet post
     */
    void postComment(int blogIndex);
    /**
     * @brief Checks post type
     * @param scrapbookIndex Index of post in post list
     * @return True if post is a blog
     */
    bool checkType(int scrapbookIndex);
    /**
     * @brief Display Blog
     * @param Blog Blog to be displayed
     * @param row Position on screen to display blog
     */
    void displayBlog(Blog* blog, int row);
    /**
     * @brief Display Tweet
     * @param Tweet Tweet to be displayed
     * @param row Position on screen to display tweet
     */
    void displayTweet(Tweet* tweet, int row);

private:
    Scrapbook* scrapbook;


    QString profileToHTML();
    QString friendsToHTML();
    QString buildContentHTML();
    QString blogToHTML(Blog *blog);
    QString tweetToHTML(Tweet *tweet);
    QString multimediaToHTML(Multimedia *media);
    void writeToHTMLFile(QString htmlText);
};


#endif // POSTUI_H
