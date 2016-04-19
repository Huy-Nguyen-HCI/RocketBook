#include "loginui.h"



LoginUI::LoginUI()
{
/**
    char mesg[]="Enter a string: ";
    char str[80];


    getstr(str);
    mvprintw(LINES - 2, 0, "You Entered: %s", str);
    getch();
    endwin();
**/


    initialize();
    echo();
    run();

}


void LoginUI::run(){

    char name[80], pass[80];
    std::string username,password;

    mvprintw(0,0,"Enter Username: ");

    username=getstr(name);

    initscr();
  //  getch();

    mvprintw(1,0,"Enter Password: ");

    password=getstr(pass);









    /**

    char response[20];
    bool continue_looping;
    int length = 0;
    std::string output;
    do{
        continue_looping = true;
        refresh();
        clear();






        if(length>0){
            output = response;
            output = output.substr(0,length);
            mvprintw(14,10,output.c_str());
        }
        int ch = getch();
        if(ch==10){
            if(length > 0) continue_looping=false;
        }
        else if(ch==263){
            if(length > 0) length--;
        }
        else if(ch==27){
            return;
        }
        else{
            response[length] = char(ch);
            length++;
        }
    } while(continue_looping);

  //  Configuration::newPlayer(output);
  **/
}
