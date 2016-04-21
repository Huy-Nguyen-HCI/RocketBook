#ifndef SCREEN_H
#define SCREEN_H
#include <curses.h>
#include <ncurses.h>
#include <iostream>


class Screen
{
public:
    Screen();
    ~Screen();
    void initialize();
    virtual void drawScreen(int v);
    int select(int max);
};

#endif // SCREEN_H
