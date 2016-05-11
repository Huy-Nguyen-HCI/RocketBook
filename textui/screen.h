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
    /**
     * @brief Class screen initialization commands
     */
    void initialize();
    /**
     * @brief Draw screen
     * @param v Value of pointer
     */
    virtual void drawScreen(int v);
    /**
     * @brief Select
     * Handles scrolling logic
     * @param max Amount of options for user to select
     * @return integer value indicating what the user has selected on the list displayed
     */
    int select(int max);
    AccountController *accountControl;
    int options;
    /**
     * @brief Adds to counter if user presses up and subtracts from counter if user pressed down
     */
    int getArrowInput();

    /**
     * @brief QStringList to std string list
     * converts QStringList into vector of std string
     * @param list QString list
     * @return std string vector with the contents of the QStringList parameter
     */
    std::vector<std::string> QtoStd(std::vector<QString> list);


};

#endif // SCREEN_H
