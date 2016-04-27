#include "enterui.h"

EnterUI::EnterUI(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();

    mvprintw(0,0,"Welcome to Rocketbook!");
    options=3;
    changeScreen(select(options));
}

void EnterUI::drawScreen(int v) {

    clear();

    // print the instructions for manipulating the Value object
    mvprintw(0, 0, "Main Menu\nPlease select one by using the arrow keys and pressing enter:");
    mvprintw(3, 8, "Login");
    mvprintw(4, 8, "Create Account");
    mvprintw(5, 8, "Quit");

    mvprintw(v+2, 5, "->");

    refresh();
}

void EnterUI::changeScreen(int selection){

    endwin();

    if(selection==1)
        login = new LoginUI(accountControl);
    else if(selection==2)
        create = new CreateAccountUI(accountControl);
    else if(selection==3)
        return;

    initialize();
    changeScreen(select(options));
}
