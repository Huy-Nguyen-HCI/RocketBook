#include "screen.h"


Screen::Screen()
{


    // initialize the screen
/**    initscr();

    // hide the cursor from view (comment this line out for debugging)
    curs_set(0);

    // disables line buffering and erase/kill character-processing
    // (interrupt and flow control characters are unaffected),
    // making characters typed by the  user  immediately
    // available to the program
    cbreak();

    // control whether characters  typed  by  the user  are echoed
    // by getch as they are typed
    noecho();

    // the user can press a function key (such as an arrow key) and
    // getch returns a single value representing the  function  key,
    // as in KEY_LEFT
    keypad(stdscr, TRUE);

    **/


}


int Screen::scrollMouse(){

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
   // scrollok(stdscr,TRUE);
  //  idlok(stdscr,TRUE);
    curs_set(0);
    cbreak();
    noecho();
    erase();

    keypad(stdscr, TRUE);
}

void Screen::drawScreen(int v){}

