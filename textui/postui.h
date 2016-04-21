#ifndef POSTUI_H
#define POSTUI_H

#include "screen.h"

class PostUI: public Screen
{
public:
    PostUI();

    void drawScreen(int v);
    void takeCommand(int selection);


    void postBlog();
    void postTweet();
    void postMedia();
};


#endif // POSTUI_H
