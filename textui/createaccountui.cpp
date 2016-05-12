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

    char name[80], pass[80], confirm[80], fullName[80], description[500];

    mvprintw(0,0,"Create Account");

    mvprintw(1,0,"Enter Username: ");
    getstr(name);

    mvprintw(2,0,"Enter Password: ");
    getstr(pass);

    mvprintw(3,0,"Enter Full Name: ");
    getstr(fullName);


    mvprintw(4,0,"Enter Description: ");
    getstr(description);
    QString serverPath;

    // check username in database
    if (accountControl->checkAccountExists(QString::fromStdString(name))) {

        //ui->message->setText("Error: Account already exists!");

        return;
    }

    // if username does not already exist, create account, copy image, and segue to dashboard
    if (accountControl->createNewAccount(QString::fromStdString(name),
                                         QString::fromStdString(pass),
                                         QString::fromStdString(fullName),
                                         serverPath,
                                         QString::fromStdString(description))) {


        mvprintw(12,5,"Account created successfully.");
        getch();

        menu=new MainMenu(accountControl);
        return;

    }

    // display error message
    mvprintw(12,5,"Error in account creation.");
    getch();
}
