#ifndef FEEDUI_H
#define FEEDUI_H

#include "screen.h"

class FeedUI: public Screen
{
public:
    FeedUI(AccountController* accountControl);
    void run();
};

#endif // FEEDUI_H
