#ifndef GROUPSCRAPBOOKUI_H
#define GROUPSCRAPBOOKUI_H

#include "screen.h"
#include "../model/scrapbook.h"
#include "../model/group.h"

/**
 * @brief Groups Scrapbook UI handles all of the functions for group scrapbook in text UI
 */

class GroupScrapbookUI: public Screen
{
public:
    /**
     * @brief GroupScrapbookUI
     * @param username Username of current user
     * @param groupId Id of indicated group
     * @param group Indicated group
     * @param groupScrapbook Group's scrapbook
     * @param friendNames List of user's friends
     */
    GroupScrapbookUI(QString username, int groupId, Group* group, Scrapbook* groupScrapbook,
                     QStringList friendNames);
    int groupId;
    Group* group;
    Scrapbook* groupScrapbook;
    QString username;
    QStringList friendNames;

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
     * @brief Display Blog
     * @param Blog Blog to be displayed
     * @param row Position on screen to display blog
     */
    void displayBlog(Blog *blog, int row);
    /**
     * @brief Display Tweet
     * @param Tweet Tweet to be displayed
     * @param row Position on screen to display tweet
     */
    void displayTweet(Tweet *tweet, int row);
    /**
     * @brief View Blog
     * Displays selected blog on screen
     * @param index Index of selected blog
     */
    void viewBlog(int index);
    /**
     * @brief View Scrapbook
     * Displays scrapbook posts on screen and allows user to scroll and select blogs to comment
     * @return location of pointer on screen
     */
    int viewScrapbook();

    /**
     * @brief Post Blog
     * Asks user for blog title and contents and creates blog post
     */
    void postBlog();
    /**
     * @brief Post Comment
     * Adds comment to specific blog
     * @param blogIndex Index of blog
     */
    void postComment(int blogIndex);
    /**
     * @brief Post Tweet
     * Asks user to enter text and creates tweet post
     */
    void postTweet();

    /**
     * @brief Adds friend to group
     * @param friendIndex Position on friends list of selected friend
     */
    void addFriend(int friendIndex);
    /**
     * @brief Displays friends on screen and allows user to select a friend
     * @return Index of selected friend
     */
    int selectFriend();
    /**
     * @brief Checks post type
     * @param scrapbookIndex Index of post in post list
     * @return True if post is a blog
     */
    bool checkType(int scrapbookIndex);

};

#endif // GROUPSCRAPBOOKUI_H
