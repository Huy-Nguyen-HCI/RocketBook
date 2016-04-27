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

    // cleanup the window and return control to bash
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

    // print the instructions for manipulating the Value object
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
    mvprintw(1,0, username.toStdString().c_str());

    QString description = "Description: " + accountControl->getUser()->getUsername();
    mvprintw(2,0, description.toStdString().c_str());
    getch();

}

void ProfileUI::editDescription(){
    erase();
    char newDescription[2000];

    mvprintw(0,0,"Edit Description");
    mvprintw(1,0,"Enter new Description: ");
    echo();
    getstr(newDescription);

   // mvprintw(12,0,"Are you sure you would like to display this as your new description?(y/n)");
   // noecho();
  //  int ch=getch();

    //if(ch==121) //y
    std::string description(newDescription);
    mvprintw(5,5,description.c_str());
        if(accountControl->getUser()->changeProfileDescription(QString::fromStdString(description)))
            mvprintw(15,0, "Updating description successful");
        else{
            mvprintw(15,0, "Updating description failed");
        }
        getch();
}
