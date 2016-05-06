#ifndef SCREEN_H
#define SCREEN_H
#include <curses.h>
#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
#include <QString>
#define timeout(QPrivateSignal)   timeout2(QPrivateSignal);
#include "../model/accountcontroller.h"


class Screen
{
public:
    Screen();
    ~Screen();
    void initialize();
    virtual void drawScreen(int v);
    int select(int max);
    AccountController *accountControl;
    int options;
    int getArrowInput();
    int scrollMouse();
    std::vector<std::string> QtoStd(std::vector<QString> list);


};

#endif // SCREEN_H
