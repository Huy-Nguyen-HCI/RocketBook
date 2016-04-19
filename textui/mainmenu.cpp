#include "mainmenu.h"

MainMenu::MainMenu(): Screen::Screen()
{

    initialize();
    changeScreen(run());

}

MainMenu::~MainMenu()
{

}

int MainMenu::run(){
    int v=1;

    // initialize the interaction loop to run
    bool continue_looping = true;

    // draw the current screen
    DrawScreen(v);

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
                v=7;
            break;
        case KEY_DOWN:
            if(v<8) //arrows goes down
            v++;
            if(v==8) //arrow goes back to top
                v=1;
            break;
        case 10: //Enter Key
            continue_looping = false;
            break;
        }

        DrawScreen(v);

    } while(continue_looping);

    return v;
}

    // a function for drawing the current screen

    void MainMenu::DrawScreen(int v) {

    // temporary display string for storing the value
    // of the displayed Value object.
    std::string display;

    // clear screen return cursor to (0,0)
    clear();

    // print the instructions for manipulating the Value object
    mvprintw(0, 0, "Main Menu\nPlease select one by using the arrow keys and pressing enter:");
    mvprintw(3, 8, "Edit Pofile");
    mvprintw(4, 8, "Post content");
    mvprintw(5, 8, "See Feeds");
    mvprintw(6, 8, "Groups");
    mvprintw(7, 8, "Chats");
    mvprintw(8, 8, "Notifications");
    mvprintw(9, 8, "Logout");

    mvprintw(v+2, 5, "->");


    refresh();
    }

    void MainMenu::changeScreen(int selection){

        // cleanup the window and return control to bash
        endwin();
/**
        //std::cout << "exiting main\n";

        if(selection==1)
            login = new LoginUI();
        else if(selection==2)
            TopP = new TopPlayer();
        **/

        /**
        else if(selection==3)
            TopG = new TopGame();
        else if(selection==4)
            UI = new ConfigUI();
        else if(selection==5){
            WUI = new WormUI();
            delete WUI;
        }
        else if(selection==6){
            RUI = new RobotsUI();
            delete RUI;
        }
        **/
        if(selection==7)
            return;

        initialize();
        changeScreen(run());

    }
