#include "screen.h"


Screen::Screen()
{
}


int Screen::select(int max){

    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    drawScreen(v);

    do {
        // draw the new screen
        refresh();
        // obtain character from keyboard
        int ch = getch();
        // operate based on input character
        switch (ch) {
        case KEY_UP:
            if(v>0) //arrow goes up
            v--;
            if(v==0) //arrow goes to bottom
                v=max;
            break;
        case KEY_DOWN:
            if(v<max+1) //arrows goes down
            v++;
            if(v==max+1) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        drawScreen(v);

    } while(continue_looping);

    return v;

}

int Screen::getArrowInput(){
    int ch = getch();

    if(ch==KEY_UP)
        return -1;
    else if(ch==KEY_DOWN)
        return 1;
    else
        return 0;
}


Screen::~Screen()
{

}

void Screen::initialize(){
    initscr();
    curs_set(0);
    cbreak();
    noecho();
    erase();

    keypad(stdscr, TRUE);
}

void Screen::drawScreen(int v){}

std::vector<std::string> Screen::QtoStd(std::vector<QString> list){
    std::vector<std::string> stringList;
    for(unsigned int i=0;i<list.size();i++)
        stringList.push_back(list.at(i).toStdString());
    return stringList;
}

