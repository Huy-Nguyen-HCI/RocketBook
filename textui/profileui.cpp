#include "profileui.h"

ProfileUI::ProfileUI(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Create new Account");
    options=3;
    takeCommand(select(options));
}



void ProfileUI::takeCommand(int selection){

    endwin();


    if(selection==1)
        viewProfile();
    else if(selection==2)
        editDescription();
    else if(selection==3)
        return;

    initialize();
    takeCommand(select(options));

}



void ProfileUI::drawScreen(int v){

    erase();

    mvprintw(0, 0, "Your Account");
    mvprintw(3, 8, "View ");
    mvprintw(4, 8, "Edit Description");

    mvprintw(5, 8, "Back");

    mvprintw(v+2, 5, "->");

    refresh();

}



void ProfileUI::viewProfile(){

    erase();
    mvprintw(0, 0, "Your Profile");


    QString username = "Username: " + accountControl->getUser()->getUsername();
    mvprintw(2,0, username.toStdString().c_str());

    QString description = "Description: " + accountControl->getUser()->getProfile()->getDescription();
    mvprintw(3,0, description.toStdString().c_str());
    mvprintw(LINES-1, 0, "Press any key to continue");
    getch();

}



void ProfileUI::editDescription(){
    erase();
    char newDescription[2000];

    mvprintw(0,0,"Edit Description");
    mvprintw(2,0,"Enter new Description: ");
    echo();
    getstr(newDescription);

    mvprintw(LINES-1,0,"Press enter to confirm change, or any key to decline change");
    noecho();
    cbreak();
    if(getch()==10){
        endwin();
        if(accountControl->getUser()->changeProfileDescription(QString::fromStdString(newDescription)))
            mvprintw(15,3, "Profile description successfully updated.");
    }
    else
        endwin();

}
