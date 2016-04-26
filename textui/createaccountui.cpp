#include "createaccountui.h"

CreateAccountUI::CreateAccountUI(AccountController* accountControl)
{

    this->accountControl=accountControl;
    initialize();
    echo();
    mvprintw(0,0,"Create new Account");
    run();
}

void CreateAccountUI::run(){

    char name[80], pass[80], desciption[500];

 //After account is created enter main menu using the line below
   //  menu=new MainMenu(accountControl);
}
