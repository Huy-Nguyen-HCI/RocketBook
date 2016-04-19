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
};

#endif // SCREEN_H
