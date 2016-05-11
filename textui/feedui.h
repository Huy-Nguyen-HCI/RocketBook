#ifndef FEEDUI_H
#define FEEDUI_H

#include "screen.h"

/**
 * @brief The chatUI screen includes all chat functionality for viewing feed and commenting
 *        on blogs.
 */


class FeedUI: public Screen
{
public:
    /**
     * @brief FeedUI
     * Displays feed and allows user to scroll through
     * @param accountController Account Controller
     */
    FeedUI(AccountController* accountControl);
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
     * @brief Displays feed on screen
     * @return position of pointer on screen
     */
    int displayFeed();

    /**
     * @brief View Blog
     * Displays selected blog on screen
     * @param index Index of selected blog
     */
    void viewBlog(int index);
    /**
     * @brief Checks post type
     * @param postIndex Post Index on post list
     * @return True if post is a blog
     */
    bool checkType(int postIndex);
    /**
     * @brief Posts a comment on blog
     * @param blogIndex Blog index on post list
     * @return True if post is a blog
     */
    void postComment(int blogIndex);
    /**
     * @brief Display Blog
     * @param Blog Blog to be displayed
     * @param row Position on screen to display blog
     * @param author Author of blog
     */
    void displayBlog(Blog* blog, int row, QString* author);
    /**
     * @brief Display Tweet
     * @param Tweet Tweet to be displayed
     * @param row Position on screen to display tweet
     * @param author Author of tweet
     */
    void displayTweet(Tweet* tweet, int row, QString* author);
};

#endif // FEEDUI_H
