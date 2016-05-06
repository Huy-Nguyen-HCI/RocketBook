#ifndef GROUPSCRAPBOOKUI_H
#define GROUPSCRAPBOOKUI_H

#include "screen.h"
#include "../model/scrapbook.h"
#include "../model/group.h"

class GroupScrapbookUI: public Screen
{
public:
    GroupScrapbookUI(QString username, int groupId, Group* group, Scrapbook* groupScrapbook,
                     QStringList friendNames);
    int groupId;
    Group* group;
    Scrapbook* groupScrapbook;
    QString username;
    QStringList friendNames;


    void drawScreen(int v);
    void takeCommand(int selection);

    void displayBlog(Blog *blog, int row);

    void displayTweet(Tweet *tweet, int row);

    void viewBlog(int index);
    int viewScrapbook();

    void postBlog();
    void postComment(int blogIndex);
    void postTweet();

    void addFriend(int friendIndex);
    int selectFriend();
    bool checkType(int scrapbookIndex);


};

#endif // GROUPSCRAPBOOKUI_H
