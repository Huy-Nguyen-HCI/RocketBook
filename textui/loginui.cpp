#include "loginui.h"

LoginUI::LoginUI(AccountController* accountControl){

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Login");
    run();

}

void LoginUI::run(){

    char name[80], pass[80];

    mvprintw(2,2,"Enter Username: ");
    getstr(name);
    initscr();
    mvprintw(3,2,"Enter Password: ");
    getstr(pass);

    if(accountControl->login(QString::fromStdString(name),QString::fromStdString(pass))){
        erase();
        refresh();
        mvprintw(2,2,"Login Successful. Welcome ");
        printw(name);
        refresh();
        menu=new MainMenu(accountControl);
    }
    else{
        erase();
        refresh();
        mvprintw(0,0,"Login Failed. Try Again.");
    }

}
