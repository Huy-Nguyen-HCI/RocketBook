#ifndef FEEDUI_H
#define FEEDUI_H

#include "screen.h"

class FeedUI: public Screen
{
public:
    FeedUI(AccountController* accountControl);
    void drawScreen(int v);
    void takeCommand(int selection);
    void run();
    void displayFeed();
    void displayBlog(Blog* blog, int row, QString* author);
    void displayTweet(Tweet* tweet, int row, QString* author);
};

#endif // FEEDUI_H
