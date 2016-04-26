#include "profileui.h"

ProfileUI::ProfileUI(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Create new Account");
    run();

}

void ProfileUI::drawScreen(int v)
{
    clear();

    // print the instructions for manipulating the Value object
    mvprintw(0, 0, "Your Account");
    mvprintw(3, 8, "Edit Description");
    mvprintw(4, 8, "Edit Full Name");
    mvprintw(5, 8, "Back");

    mvprintw(v+2, 5, "->");

    refresh();
}



void ProfileUI::displayInfo()
{
    erase();
    QString username = "Username: " + accountControl->getUser()->getUsername();
    mvprintw(1,0, username.toStdString().c_str());
}

void ProfileUI::run(){

    endwin();
    displayInfo();
    initialize();


}
